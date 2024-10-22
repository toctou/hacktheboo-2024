import random

def even_or_odd(n):
    if n % 2 == 0:
        return 'even'
    return 'odd'

def gen_question():
    n = random.randint(1, 100_000)

    return f'{n}', f'{even_or_odd(n)}'
