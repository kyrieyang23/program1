# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random
import string

WORDLIST_FILENAME = "words.txt"

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    wordTest = ''
    if lettersGuessed == [] and secretWord != '':
        return False
    else:
        for i in secretWord:
            for j in lettersGuessed:
                if i == j:
                    wordTest = wordTest + j
        if len(wordTest) == len(secretWord):
            return True
        elif len(wordTest) != len(secretWord) and len(wordTest) < len(secretWord):
            return False
        else:
            return True
    
def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    result = ''
    for letter in secretWord:
        if letter in lettersGuessed:
            result += letter
        else:
            result += '_'
    return result

def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    availableLetter = list(set(string.ascii_lowercase)-set(lettersGuessed))
    availableLetter.sort()
    return ''.join(availableLetter)
    

def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    print("\nWelcome to the game Hangman!")
    print("I am thinking of a word that is " + str(len(secretWord)) + " letters long")
    round = 8
    Gletter = []
    Rletter = getGuessedWord(secretWord, Gletter)
    while round > 0:
        print("----------")
        print("You have " + str(round) + " guesses left")
        print("Available Letters: " + getAvailableLetters(Gletter))
        userGuess = str(input("Please guess a letter: "))
        Guess = userGuess.lower()
        if Guess in Gletter:
            print("Oops! You've already guessed that letter: " + Rletter)
        elif Guess in secretWord:
            Gletter.append(Guess)
            Rletter = getGuessedWord(secretWord, Gletter)
            print("Good guess: " + Rletter)
            if Rletter == secretWord:
                print("----------")
                break
        else:
            print("Oops! That letter is not in my word: " + Rletter)
            Gletter.append(Guess)
            round -= 1
    if Rletter == secretWord:
        return print("Congratulations, you won!")
    else:
        return print("----------\nSorry, you ran out of guesses. The word was " + secretWord)
print(hangman(chooseWord(wordlist)))





# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)

# secretWord = chooseWord(wordlist).lower()
# hangman(secretWord)
