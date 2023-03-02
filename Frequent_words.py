#Function that takes a list as an input. 
#The list will be sorted in a dictionary, with the word as the key, 
#and the value as how many times the word was said

def frequent_words(script):
  words_frequency_pairs = {}
  max_value = 0
  m_word = [0, ""]
  for sentence in script:
    for word in sentence.split():
      IfWord = word in words_frequency_pairs
      if IfWord == True:
        word_count = words_frequency_pairs.get(word)
        words_frequency_pairs.update({word: word_count + 1})
        word_count = words_frequency_pairs.get(word)
      #adds word into dictionary
        if word_count >= max_value:
          max_value = word_count
          m_word[0] = max_value
          m_word[1] = word
          print(word_count)
        #checks for and updates most frequently used word
      else:
        words_frequency_pairs.update({word: 1})
      #updates word count
  return m_word
