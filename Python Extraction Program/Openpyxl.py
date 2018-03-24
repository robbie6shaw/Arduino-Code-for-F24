import openpyxl 

wb = openpyxl.load_workbook('DataExample.xlsx')

# grab the active worksheet
ws = wb.active

# Data can be assigned directly to cells
ws['F8'] = 42
wb.save()
print('Finished')