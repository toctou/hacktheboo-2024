import random

def gen_question():
    with open('story.txt') as f:
        text = random.choice(f.readlines()).strip()

    return f'{text}', f'{text[::-1]}'
