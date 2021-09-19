# ECOO '20 P4 - Ring
# compiled not interpreted

x = 0

class Function:
    def __init__(self) -> None:
        self.args = []
        self.funcs = {}
        self.pass_args = ""

    def parse(self, arg):
        if arg[0][0] == 'E':
            self.pass_args = ""
        elif self.pass_args:
            self.funcs[self.pass_args].parse(arg)
        elif arg[0][0] == 'A':
            self.args.append(('+', int(arg[1])))
        elif arg[0][0] == 'S':
            self.args.append(('-', int(arg[1])))
        elif arg[0][0] == 'M':
            self.args.append(('*', int(arg[1])))
        elif arg[0][0] == 'F':
            self.pass_args = arg[1]
            self.funcs[arg[1]] = Function()
        else:
            self.args.append(('f', arg[1]))

    def execute(self):
        global x
        for arg in self.args:
            if arg[0] == '+':
                x += arg[1]
            elif arg[0] == '-':
                x -= arg[1]
            elif arg[0] == '*':
                x *= arg[1]
            else:
                self.funcs[arg[1]].execute()
        x %= 1000000007

for i in range(int(input())):
    main = Function()
    x = 0
    for j in range(int(input())):
        main.parse(input().split())
    main.execute()
    print(x)
