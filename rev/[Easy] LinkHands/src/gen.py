#!/usr/bin/env python3

flag = "HTB{4_br34k_1n_th3_ch41n_0e343f537ebc}"

def output_part(var_name, part):
    output = f"struct ListNode {var_name} = "
    for c in part[:-1]:
        output += f"ENTRY('{c}', "
    output += f"LAST_ENTRY('{part[-1]}')"
    output += ")" * (len(part) - 1)
    output += ";\n"
    print(output)

part1, part2 = flag[:len(flag)//2], flag[len(flag)//2:]

output_part('part1', part1)
output_part('part2', part2)
