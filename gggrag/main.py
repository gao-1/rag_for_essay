import os
from dotenv import load_dotenv
from pdf_loader import load_pdf
from vector_store import create_vector_store, load_vector_store
from rag_qa import setup_qa_chain

def init_vector_store(pdf_path):
    """初始化向量存储"""
    chunks = load_pdf(pdf_path)
    return create_vector_store(chunks)

def main():
    load_dotenv()
    os.environ["ZHIPUAI_API_KEY"] = os.getenv("ZHIPU_API_KEY")
    
    # 检查是否需要初始化向量存储
    if not os.path.exists("./chroma_db"):
        pdf_path = "./7090.pdf"  # 实际的PDF路径
        vector_store = init_vector_store(pdf_path)
    else:
        vector_store = load_vector_store()
    
    qa_chain = setup_qa_chain(vector_store)
    
    while True:
        question = input("\n请输入您的问题 (输入 'q' 退出): ")
        if question.lower() == 'q':
            break
        
        result = qa_chain({"query": question})
        print("\n回答:", result["result"])
        print("\n参考来源:", "来自文档的第", 
              [doc.metadata.get('page', '未知') for doc in result["source_documents"]], "页")

if __name__ == "__main__":
    main()