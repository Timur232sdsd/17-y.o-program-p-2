import xlrd

# Открываем файл Excel
workbook = xlrd.open_workbook('9-228.xls')
sheet = workbook.sheet_by_index(0)

def is_interesting(cell_value, row_values, column_values):
    if row_values.count(cell_value) == 1 and column_values.count(cell_value) <= 169:
        return True
    return False

interesting_rows_count = 0
for row_idx in range(sheet.nrows):
    row_values = sheet.row_values(row_idx)
    for col_idx in range(sheet.ncols):
        cell_value = sheet.cell_value(row_idx, col_idx)
        column_values = [sheet.cell_value(i, col_idx) for i in range(sheet.nrows)]
        if is_interesting(cell_value, row_values, column_values):
            interesting_rows_count += 1
            break  

print(interesting_rows_count)
