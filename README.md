# PDF Content Recognizer (RAG-based)

This project is a Retrieval-Augmented Generation (RAG) system designed to **improve the recognition of tables, images, and formulas** in academic papers. By enhancing the extraction and processing of these elements, the system ensures more accurate responses to user queries. It leverages the Chroma vector database for efficient content storage and retrieval.

## Features

- **Enhanced Recognition**: Improved methods for identifying and extracting tables, images, and formulas from PDFs.
- **RAG-based Query System**: Combines retrieval and generation to provide accurate answers based on recognized content.
- **Chroma Vector Database**: Utilizes Chroma for efficient storage and retrieval of document embeddings.
- **Customizable Input**: Modify the input file name in `pdf_loader.py` to process different PDFs.
- **Simple Execution**: Run the project using the `main.py` script.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/pdf-content-recognizer.git
   cd pdf-content-recognizer
