
# 📊 C-STATS Assignment
A C-based application that reads a text file and computes basic Natural Language Processing (NLP) statistics.
This project also focuses on dynamic memory allocation and string manipulation in C.

## 📄 Function Descriptions

### 1️⃣ Read Sentences from File

- **Input:**  
  A file containing multiple sentences, where each line represents one sentence.

- **Output:**  
  Returns an array of pointers to the sentences (strings).

- **Purpose:**  
  Reads the input file line by line and stores each sentence into an array of strings.


### 2️⃣ Create Unigram Structure

- **Input:**  
  An array of pointers to strings (sentences).

- **Output:**  
  Returns an array of `Unigram` structures.

- **Unigram Structure:**
  - `word1`: stores a word.
  - `count`: initialized to 0.

- **Purpose:**  
  Generates a structure to hold each unique word and a counter.


### 4️⃣ Count Unigram Frequencies

- **Input:**  
  - An array of pointers to strings (sentences).  
  - Pointer to an array of `Unigram` structures.

- **Output:**  
  Updates the `Unigram` array by incrementing the `count` value.

- **Purpose:**  
  Calculates the frequency of each word in the input sentences.

---


## 📦 Prerequisites
- Ensure you have GCC installed (`gcc --version` to check).
- Header files are located inside the `include/` directory.
- Source files are located inside the `src/` directory.

---

## 🛠️ Compilation Instructions

1. Open your terminal and navigate to the project root folder:

```bash
cd /path/to/C-STATS-ASSIGNMENT
```

2. Compile the project using:

```bash
gcc -Iinclude main.c src/file_read.c src/unigram.c -o my_program
```

3. Run the program:

```bash
./my_program
```

---

## 📂 Project Structure

```
C-STATS-ASSIGNMENT/
├── include/
│   └── file_read.h
│   └── unigram.h
├── src/
│   └── file_read.c
│   └── unigram.c
├── main.c
├── input.txt
├── README.md
└── my_program (generated after compilation)
```

---

## 📝 Notes
- Make sure `input.txt` exists in the root directory or update your `main.c` with the correct path.
- `-Iinclude` tells the compiler to look for header files inside the `include/` folder.

---


