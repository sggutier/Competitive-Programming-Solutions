#!/usr/bin/env python3

def main():
    while True:
        lin = ''
        try:
            lin = input()
        except:
            break
        print('%.3f' % eval(lin))


main()
