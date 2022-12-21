import random

class account:
    def __init__(self):
        self.credit = 0
        self.outcome = 0
        self.debt = 20000000
        
    def inoutcome(self):
        self.credit += 2200000
        self.outcome = random.randrange(145, 175) * 10000
        self.credit -= self.outcome
        self.credit -= (300000 + int((self.debt * 0.05)/12))
        self.debt -= 300000
   
    def interest(self):
        self.credit += int(self.credit*0.03)