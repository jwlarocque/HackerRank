# they tell me the cool people use python for NLP
# and it's easier
import re;


abbreviations = re.compile("([A-Z]|(Dr)|(Mr)|(Ms)|(Mrs))\.")
punctuations = [".", "!", "?"]
quotations = ["\"", "\'"]
paragraph = raw_input() + " "
print
print
while any(element in paragraph for element in punctuations):
    for index in range(0, len(paragraph)):
        if paragraph[index] in punctuations:
            currentAbbrevs = abbreviations.match(paragraph[:index + 1])
            if (currentAbbrevs == None or currentAbbrevs.end() != index) and paragraph[index + 1] not in quotations:
                print paragraph[:index + 1]
                print
                paragraph = paragraph[index + 1:]
                break
print paragraph
