class ProductOfNumbers:
    def __init__(self):
        self.stream = [1]
        self.zero = -1

    def add(self, num: int) -> None:
        if num == 0:
            self.zero = len(self.stream)
            self.stream.append(1)
        else:
            pro = self.stream[-1]*num
            self.stream.append(pro)


    def getProduct(self, k: int) -> int:
        if self.zero >= len(self.stream)-k:
            return 0
        return int(self.stream[-1]/self.stream[-k-1])


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)