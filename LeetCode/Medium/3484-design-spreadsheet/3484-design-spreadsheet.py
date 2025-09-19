class Spreadsheet:

    def __init__(self, rows: int):
        self.sheet = {}
        self.sheet = defaultdict(int)
        

    def setCell(self, cell: str, value: int) -> None:
        self.sheet[cell] = value
        

    def resetCell(self, cell: str) -> None:
        self.sheet[cell] = 0

    def getValue(self, formula: str) -> int:
        formula = formula[1:]
        val1, val2 = formula.split("+")
        print(val1.isnumeric())
        val1 = int(val1) if val1.isnumeric() else self.sheet[val1]
        val2 = int(val2) if val2.isnumeric() else self.sheet[val2]
        return val1 + val2



# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)