import random

def gen_question():
    a, b = random.randint(1, 10_000), random.randint(1, 10_000)

    return f'{a}\n{b}', f'{a+b}'
