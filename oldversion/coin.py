import random

class Coin:
    def __init__(self):
        self.origin_price = 0
        self.year = 2022
        self.month = 1
        self.date = 1
        self.month_min = 0
        self.month_max = 0
        self.month_max_date = 0
        self.month_min_date = 0
        self.year_min = 0
        self.year_max = 0
        self.year_max_month = 0
        self.year_max_date = 0
        self.year_min_month = 0
        self.year_min_date = 0
        self.bb_rate = 0
        self.market =" "
        self.up = 0
        self.s_up = 0
        self.s_down = 0
        self.down = 0
        self.vol = 0
        self.s_price = 0
        self.e_price = 0
        self.fluctation = 0

    #거래량 계산 함수
    def volume(self):
        dif = self.month_max - self.month_min
        rate = dif/self.month_min
        if(rate<0.025):
            ratio = (rate+1)*(rate+1)
        elif(rate<0.05):
            ratio = (rate+1)*(rate+1)*1.25
        elif(rate<0.01):
            ratio = (rate+1)*(rate+1)*1.5
        else:
            ratio = (rate+1)*(rate+1)*2
        self.vol = ratio*self.month_max
        return self.vol
    
    #등락 여부 결정 함수
    def UpAndDown(self):
        pm = random.randrange(0,10000)
        if(pm < 1000):
            self.down = 0
            self.s_down = 0
        elif(pm < 1500):
            self.s_down = 0
        elif(4000 < pm < 5000):
            self.s_down = 0
            self.s_up = 0
        elif(pm > 8500):
            self.up = 0
            self.s_up = 0
        elif(pm > 8000):
            self.s_up = 0

        if((pm<50 or self.up > 0) and (self.down == 0)):
            self.bb_rate = 0
            self.s_up = 0
            self.s_down = 0
            self.up+=1
            self.market = "대호황"
            return self.bb_rate
        elif((pm<1500 or self.s_up > 0) and (self.s_down == 0 and self.down == 0)):
            self.bb_rate = 1
            self.up = 0
            self.s_up+=1
            self.market = "호황"
            return self.bb_rate
        elif(pm<8500 and self.s_down == 0 and self.down == 0):
            self.bb_rate = 2
            self.market = "보합"
            return self.bb_rate
        elif((pm<9950 or self.s_down > 0) and self.down == 0):
            self.bb_rate = 3
            self.s_down+=1
            self.market = "불황"
            return self.bb_rate
        elif(pm<10000 or self.down > 0):
            self.bb_rate = 4
            self.down+=1
            self.market = "대불황"
            return self.bb_rate

    #일간 변동 함수
    def day(self):
        for k in range(0,24):
            for j in range(0,60):
                pm = random.randrange(0,5)
                for i in range(0,100):
                    #현 가격에 따른 변동폭 지정
                    base = self.origin_price/5000000
                    #상승, 하락, 보합장 지정
                    if(self.bb_rate == 0):          #대호황
                        if(pm<4):
                            self.origin_price+=base
                        else:
                            self.origin_price-=base
                    elif(self.bb_rate == 1):        #호황
                        if(pm<3):
                            self.origin_price+=base
                        else:
                            self.origin_price-=base
                    elif(self.bb_rate == 2):        #보합
                        if(pm<2):
                            self.origin_price+=base
                        elif(pm<3):
                            self.origin_price=self.origin_price
                        else:
                            self.origin_price-=base
                    elif(self.bb_rate == 3):        #불황
                        if(pm<1):
                            self.origin_price+=base
                        elif(pm<3):
                            self.origin_price=self.origin_price
                        else:
                            self.origin_price-=base
                    elif(self.bb_rate == 4):        #대불황
                        if(pm<1):
                            self.origin_price+=base
                        else:
                            self.origin_price-=base

    #월초 초기화 함수 (월 시가, 월 최고가/최저가, 최고가/최저가 일, 연간 최고가/최저가, 연간 최고가/최저가 월/일)
    def month_setting(self):
        self.s_price = self.origin_price
        self.date = 1
        self.month_max = self.s_price
        self.month_min = self.s_price
        self.month_max_date = 1
        self.month_min_date = 1
        if(self.month==1):
            self.year_max = self.origin_price  #연간 최고가
            self.year_min = self.origin_price  #연간 최저가
            self.year_max_month = 1       #최고가 월
            self.year_max_date = 1         #최고가 일
            self.year_min_month = 1       #최저가 월
            self.year_min_date = 1         #최고가 일
        else:
            pass

    #월 지정 함수
    def date_range(self):
        if(self.month==1 or self.month==3 or self.month==5 or self.month==7 or self.month==8 or self.month==10 or self.month==12): #1,3,5,7,8,10,12월
            return 32
        elif(self.month==4 or self.month==6 or self.month==9 or self.month==11):    #4,6,9,11월
            return 31
        elif(self.month==2): #2월
            return 29

    #월간 고/저가 갱신 함수
    def month_MAX_MIN(self):
        if(self.origin_price > self.month_max):
            self.month_max = self.origin_price
            self.month_max_date = self.date
        elif(self.origin_price < self.month_min):
            self.month_min = self.origin_price
            self.month_min_date = self.date
        else:
            pass
        self.date+=1

    #연간 고/저가 갱신 함수
    def year_MAX_MIN(self):
        if(self.month_max>self.year_max):
            self.year_max = self.month_max
            self.year_max_month = self.month
            self.year_max_date = self.month_max_date
        
        if(self.month_min<self.year_min):
            self.year_min = self.month_min
            self.year_min_month = self.month
            self.year_min_num = self.month_min_date

        self.e_price = self.origin_price
        self.fluctation = (self.e_price/self.s_price-1)*100

        if(self.month<12):
            self.month+=1
        elif(self.month==12):
            self.year+=1 #다음 해로
            self.month=1
        else:
            pass
