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
  
  #This next section is technically part of a different assignment, as it returns a different value
  #grabs top 5 interesting words 
  #This works by sorting the dictionary of words, and then if the top words aren't in the common_words list,
  #it doesn't get included in the topfive list
  
  common_words = ['the', 'a', 'an', 'and', 'of', 'in', 'to', 'is', 'are', 'be', 'i', 'he', 'she', 'you', 'with', 'on', 'it', 'this', 'that', 'we', 'what', 'his', 'at', 'for', 'him', 'her', 'hers']
  topfive = []
  topfreqword = ""
  topfreqcount = 0
  i = 0
  while i != 5:
    for key, value in words_frequency_pairs.items():
      if key not in topfive:
        if value > topfreqcount:
            topfreqword = key
            topfreqcount = value
    topfive.append([topfreqcount, topfreqword])
    if topfreqword in words_frequency_pairs:
      del words_frequency_pairs[topfreqword]
    i += 1
    topfreqcount = 0
  #return topfive
  
  
  return m_word
