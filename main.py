import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import bankaccount
import SWG
import XRP

player = bankaccount.account()

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):
        self.yearAndmonth = QLabel(' ', self)
        self.yearAndmonth.setGeometry(350, 5, 100, 30)

        self.swg_lbl = QLabel('Swag / SWG', self)
        self.swg_lbl.setGeometry(10, 5, 190, 30)
        self.swg_tb = QTextBrowser(self)
        self.swg_tb.setAcceptRichText(True)
        self.swg_tb.setOpenExternalLinks(True)
        self.swg_tb.setGeometry(10, 30, 190, 100)

        self.xrp_lbl = QLabel('Reaple / XRP', self)
        self.xrp_lbl.setGeometry(10, 130, 190, 30)
        self.xrp_tb = QTextBrowser(self)
        self.xrp_tb.setAcceptRichText(True)
        self.xrp_tb.setOpenExternalLinks(True)
        self.xrp_tb.setGeometry(10, 155, 190, 100)

        self.account_lbl = QLabel('금월 잔고', self)
        self.account_lbl.setGeometry(210, 130, 190, 30)
        self.account_tb = QTextBrowser(self)
        self.account_tb.setAcceptRichText(True)
        self.account_tb.setOpenExternalLinks(True)
        self.account_tb.setGeometry(210, 155, 190, 100)

        turn_end = QPushButton('&턴 종료', self)
        turn_end.setCheckable(True)
        turn_end.clicked.connect(self.RUN)
        turn_end.move(205, 30)

        quit = QPushButton('&종료', self)
        quit.setCheckable(True)
        quit.clicked.connect(QCoreApplication.instance().quit)
        quit.move(300, 30)

        self.setWindowTitle('Virtual Coin Trading System')
        self.setGeometry(500, 300, 410, 270)
        self.show()

    def RUN(self):
        self.yearAndmonth.setText(str(SWG.swag.year) + "-" + str(SWG.swag.month))
        player.inoutcome()
        if(SWG.swag.month%3 == 0):
            player.interest()
        SWG.run()
        XRP.run()
        self.swagPrint()
        self.xrpPrint()
        self.accountPrint()

    def swagPrint(self):
        self.swg_tb.clear()
        s_price = "시가 : ₩" + str(round(SWG.swag.s_price, 2))
        e_price = "종가 : ₩" + str(round(SWG.swag.e_price, 2))
        month_max = "고가 : ₩" + str(round(SWG.swag.month_max, 2))
        month_min = "저가 : ₩" + str(round(SWG.swag.month_min, 2))
        volume = "거래량 : " + str(SWG.swag.vol) + " SWG"
        fluctation = "등락률 : " + str(round(SWG.swag.fluctation, 2)) + "%"
        self.swg_tb.append(s_price)
        self.swg_tb.append(e_price)
        self.swg_tb.append(month_max)
        self.swg_tb.append(month_min)
        self.swg_tb.append(volume)
        self.swg_tb.append(fluctation)

    def xrpPrint(self):
        self.xrp_tb.clear()
        s_price = "시가 : ₩" + str(round(XRP.reaple.s_price, 2))
        e_price = "종가 : ₩" + str(round(XRP.reaple.e_price, 2))
        month_max = "고가 : ₩" + str(round(XRP.reaple.month_max, 2))
        month_min = "저가 : ₩" + str(round(XRP.reaple.month_min, 2))
        volume = "거래량 : " + str(XRP.reaple.vol) + " SWG"
        fluctation = "등락률 : " + str(round(XRP.reaple.fluctation, 2)) + "%"
        self.xrp_tb.append(s_price)
        self.xrp_tb.append(e_price)
        self.xrp_tb.append(month_max)
        self.xrp_tb.append(month_min)
        self.xrp_tb.append(volume)
        self.xrp_tb.append(fluctation)

    def accountPrint(self):
        self.account_tb.clear()
        credit = "잔고 : ₩" + str(player.credit)
        outcome = "생활비 지출 : ₩" + str(player.outcome)
        self.account_tb.append(credit)
        self.account_tb.append(outcome)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())