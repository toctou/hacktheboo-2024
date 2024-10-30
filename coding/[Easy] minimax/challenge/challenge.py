import random

def gen_question(): 
    qu = [round(random.uniform(0.01, 1999.99), 2) for _ in range(200)]
    
    _min = min(qu)
    _max = max(qu)

    qu_str = [str(q) for q in qu]

    return ' '.join(qu_str), f'{_min}\n{_max}'
