# openpyxl을 가져옵니다.
import openpyxl

# 워크북(엑셀파일)을 새로 만듭니다.
wb = openpyxl.Workbook()
# 워크북(엑셀파일)을 원하는 이름으로 저장합니다.
wb.save('test.xlsx')

sheet = wb.active
# A1셀에 hello world!를 입력합니다.
sheet['A1'] = 'hello world!'
sheet['A2'] = 'hello world!'

sheet.cell(row=2, column=3).value = 'hello'

# 워크북(엑셀파일)을 원하는 이름으로 저장합니다.
wb.save('test.xlsx')
