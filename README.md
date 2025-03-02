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

2. **Install dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

3. **Set up Chroma**:
   Follow the [Chroma documentation](https://docs.trychroma.com/) to install and configure Chroma.

## Usage

1. **Modify the Input File**:
   - Open `pdf_loader.py` and update the `filename` variable with the path to your target PDF file.

2. **Run the Project**:
   - Execute the `main.py` script to process the PDF and store its content in the Chroma database.
   ```bash
   python main.py
   ```

3. **Query the System**:
   - Use the provided query interface to ask questions. The system will retrieve relevant information from the recognized content (tables, images, formulas) and generate accurate responses.

## Project Structure

```
pdf-content-recognizer/
├── pdf_loader.py          # Script to load and extract content from PDFs
├── main.py                # Main script to run the RAG pipeline
├── chroma_db/             # Directory for Chroma database files
├── requirements.txt       # List of dependencies
└── README.md              # This file
```

## Example Queries

After running the project, you can query the system with questions like:
- "What data is shown in the table on page 7?"
- "Can you describe the image in Figure 2?"
- "What is the meaning of the formula on page 10?"

The system will recognize the relevant content (tables, images, or formulas) and generate a response.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
