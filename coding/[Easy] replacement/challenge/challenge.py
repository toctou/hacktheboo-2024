from string import ascii_letters

import random

def gen_question():
    with open('story.txt') as f:
        text = random.choice(f.readlines()).strip()

    to_replace = random.choice(text)
    to_use = random.choice(ascii_letters)

    return f'{text}\n{to_replace}\n{to_use}', f'{text.replace(to_replace, to_use)}'

print(gen_question())
