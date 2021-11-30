import pyperclip

out = ''

while True:
    s = input()
    out += s + '\n'
    if s == '};':
        break

pyperclip.copy(out)