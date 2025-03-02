from langchain_community.embeddings import ZhipuAIEmbeddings
from langchain.vectorstores import Chroma

def create_vector_store(chunks):
    embeddings = ZhipuAIEmbeddings()
    vector_store = Chroma.from_texts(
        texts=chunks,
        embedding=embeddings,
        persist_directory="./chroma_db"
    )
    vector_store.persist()  # 确保数据被保存
    return vector_store

def load_vector_store():
    embeddings = ZhipuAIEmbeddings()
    return Chroma(persist_directory="./chroma_db", embedding_function=embeddings)