# levenshtein_text_corrector
# The **Levenshtein distance** is a measure of the difference between two strings. It calculates the minimum number of single-character edits (insertions, deletions, or substitutions) required to change one string into another.

#This project implements a **Levenshtein Distance** algorithm to correct words in a given input text. The program compares each word in the input against a predefined dictionary and replaces any word not found in the dictionary with its closest match based on the Levenshtein distance.


# How It Works
1. The user provides the size of the dictionary and the number of lines to be corrected.
2. The program reads the dictionary and then processes each line of input text.
3. For each word in the input text:
   - If the word is found in the dictionary, it is printed as it is.
   - If the word is not found, the program finds the closest word from the dictionary using the Levenshtein distance and prints the closest match.
