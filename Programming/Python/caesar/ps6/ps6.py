import string

### DO NOT MODIFY THIS FUNCTION ###
def load_words(file_name):
    '''
    file_name (string): the name of the file containing 
    the list of words to load    
    
    Returns: a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    '''
    
    #print('Loading word list from file...')
    # inFile: file
    in_file = open(file_name, 'r')
    # line: string
    line = in_file.readline()
    # word_list: list of strings
    word_list = line.split()
    #print('  ', len(word_list), 'words loaded.')
    in_file.close()
    return word_list

### DO NOT MODIFY THIS FUNCTION ###
def is_word(word_list, word):
    '''
    Determines if word is a valid word, ignoring
    capitalization and punctuation

    word_list (list): list of words in the dictionary.
    word (string): a possible word.
    
    Returns: True if word is in word_list, False otherwise

    Example:
    >>> is_word(word_list, 'bat') returns
    True
    >>> is_word(word_list, 'asdf') returns
    False
    '''
    word = word.lower()
    word = word.strip(" !@#$%^&*()-_+={}[]|\:;'<>?,./\"")
    return word in word_list

### DO NOT MODIFY THIS FUNCTION ###
def get_story_string():
    """
    Returns: a joke in encrypted text.
    """
    f = open("story.txt", "r")
    story = str(f.read())
    f.close()
    return story

WORDLIST_FILENAME = 'words.txt'

class Message(object):
    ### DO NOT MODIFY THIS METHOD ###
    def __init__(self, text):
        '''
        Initializes a Message object
                
        text (string): the message's text

        a Message object has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words
        '''
        self.message_text = text
        self.valid_words = load_words(WORDLIST_FILENAME)

    ### DO NOT MODIFY THIS METHOD ###
    def get_message_text(self):
        '''
        Used to safely access self.message_text outside of the class
        
        Returns: self.message_text
        '''
        return self.message_text

    ### DO NOT MODIFY THIS METHOD ###
    def get_valid_words(self):
        '''
        Used to safely access a copy of self.valid_words outside of the class
        
        Returns: a COPY of self.valid_words
        '''
        return self.valid_words[:]
        
    def build_shift_dict(self, shift):
        '''
        Creates a dictionary that can be used to apply a cipher to a letter.
        The dictionary maps every uppercase and lowercase letter to a
        character shifted down the alphabet by the input shift. The dictionary
        should have 52 keys of all the uppercase letters and all the lowercase
        letters only.        
        
        shift (integer): the amount by which to shift every letter of the 
        alphabet. 0 <= shift < 26

        Returns: a dictionary mapping a letter (string) to 
                 another letter (string). 
        '''
        lowerlist = [string.ascii_lowercase + string.ascii_lowercase + string.ascii_lowercase]
        upperlist = [string.ascii_uppercase + string.ascii_uppercase + string.ascii_uppercase]
        self.buildDict = {}
        for i in range(52):
            if i < 26:
                self.buildDict[lowerlist[0][i]] = lowerlist[0][i+shift]
            else:
                self.buildDict[upperlist[0][i]] = upperlist[0][i+shift]
        return self.buildDict

    def apply_shift(self, shift):
        '''
        Applies the Caesar Cipher to self.message_text with the input shift.
        Creates a new string that is self.message_text shifted down the
        alphabet by some number of characters determined by the input shift        
        
        shift (integer): the shift with which to encrypt the message.
        0 <= shift < 26

        Returns: the message text (string) in which every character is shifted
             down the alphabet by the input shift
        '''
        punctuation = string.punctuation + ' '
        digits = string.digits
        newtext = []
        lowerlist = [string.ascii_lowercase + string.ascii_lowercase + string.ascii_lowercase]
        upperlist = [string.ascii_uppercase + string.ascii_uppercase + string.ascii_uppercase]
        applybuildDict = {}
        for i in range(52):
            text = Message.get_message_text(self)
            if i < 26:
                applybuildDict[lowerlist[0][i]] = lowerlist[0][i+shift]
            else:
                applybuildDict[upperlist[0][i]] = upperlist[0][i+shift]
        for i in text:
            if i in punctuation or i in digits:
                newtext.append(i)
            else:
                newtext.append(applybuildDict[i])
        text = ''.join(newtext)
        return text
            

class PlaintextMessage(Message):
    def __init__(self, text, shift):
        '''
        Initializes a PlaintextMessage object        
        text (string): the message's text
        shift (integer): the shift associated with this message

        A PlaintextMessage object inherits from Message and has five attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
            self.shift (integer, determined by input shift)
            self.encrypting_dict (dictionary, built using shift)
            self.message_text_encrypted (string, created using shift)

        Hint: consider using the parent class constructor so less 
        code is repeated
        '''
        Message.__init__(self, text)
        self.shift = shift
        self.encrypting_dict = Message.build_shift_dict(self, shift)
        self.message_text_encrypted = Message.apply_shift(self, shift)

    def get_shift(self):
        '''
        Used to safely access self.shift outside of the class
        
        Returns: self.shift
        '''
        return self.shift

    def get_encrypting_dict(self):
        '''
        Used to safely access a copy self.encrypting_dict outside of the class
        
        Returns: a COPY of self.encrypting_dict
        '''
        return  self.encrypting_dict.copy()

    def get_message_text_encrypted(self):
        '''
        Used to safely access self.message_text_encrypted outside of the class
        
        Returns: self.message_text_encrypted
        '''
        return self.message_text_encrypted

    def change_shift(self, shift):
        '''
        Changes self.shift of the PlaintextMessage and updates other 
        attributes determined by shift (ie. self.encrypting_dict and 
        message_text_encrypted).
        
        shift (integer): the new shift that should be associated with this message.
        0 <= shift < 26

        Returns: nothing
        '''
        self.shift = shift
        self.encrypting_dict = Message.build_shift_dict(self, shift)
        self.message_text_encrypted = Message.apply_shift(self, shift)
        return None


class CiphertextMessage(Message):
    def __init__(self, text):
        '''
        Initializes a CiphertextMessage object
                
        text (string): the message's text

        a CiphertextMessage object has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
        '''
        Message.__init__(self, text)

    def decrypt_message(self):
        '''
        Decrypt self.message_text by trying every possible shift value
        and find the "best" one. We will define "best" as the shift that
        creates the maximum number of real words when we use apply_shift(shift)
        on the message text. If s is the original shift value used to encrypt
        the message, then we would expect 26 - s to be the best shift value 
        for decrypting it.

        Note: if multiple shifts are  equally good such that they all create 
        the maximum number of you may choose any of those shifts (and their
        corresponding decrypted messages) to return

        Returns: a tuple of the best shift value used to decrypt the message
        and the decrypted message text using that shift value
        '''
        finalcount = []
        for s in range(26):
            count = 0
            best = 26-s
            text = Message.apply_shift(self,best)
            testlist = text.split(' ')
            for i in range(len(testlist)):
                if is_word(Message.get_valid_words(self), testlist[i]):
                    count += 1
                if (i+1) is len(testlist):
                    finalcount.append(count)
                if count is len(testlist) and s != 0:
                    finaltuple = (best, text)
                    return finaltuple
                if count is len(testlist) and s == 0:
                    finaltuple = (0, text)
                    return finaltuple
        for s in range(26):
            count = 0
            best = 26-s
            text = Message.apply_shift(self,best)
            testlist = text.split(' ')
            for i in range(len(testlist)):
                if is_word(Message.get_valid_words(self), testlist[i]):
                    count += 1
                if count is max(finalcount) and s != 0:
                    finaltuple = (best, text)
                    return finaltuple
                if count is max(finalcount) and s == 0:
                    finaltuple = (0, text)
                    return finaltuple
                
def decrypt_story():       
    story = CiphertextMessage(get_story_string())
    return story.decrypt_message()

plaintext = PlaintextMessage('My name is Yang', 5)
print('Expected Output: Rd sfrj nx Dfsl')
print('Actual Output:', plaintext.get_message_text_encrypted())
ciphertext = CiphertextMessage('Rd sfrj nx Dfsl')
print('Expected Output:', (21, 'My name is Yang'))
print('Actual Output:', ciphertext.decrypt_message())
"""
print()
text = get_story_string()
new = CiphertextMessage(text)
print("secret story : " + text)
print()
print("translate : " + str(new.decrypt_message()))
"""

