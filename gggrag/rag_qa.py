from langchain_community.chat_models import ChatZhipuAI
from langchain.chains import RetrievalQA
from langchain.prompts import PromptTemplate 

def setup_qa_chain(vector_store):
    llm = ChatZhipuAI(
        model_name="glm-4-flash", 
        
    )
    
    prompt_template = """请基于以下提供的上下文信息，简洁专业地回答问题。如果无法从上下文中找到答案，请直接回复"根据已知信息无法回答该问题"。

上下文信息：
{context}

问题：{question}

回答："""
    
    PROMPT = PromptTemplate(
        template=prompt_template,
        input_variables=["context", "question"]
    )
    
    qa_chain = RetrievalQA.from_chain_type(
        llm=llm,
        chain_type="stuff",
        retriever=vector_store.as_retriever(search_kwargs={"k": 3}),
        chain_type_kwargs={"prompt": PROMPT},
        return_source_documents=True  # 返回源文档信息
    )
    return qa_chain