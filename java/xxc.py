import xlsxwriter

def create_beautiful_tracker():
    file_name = 'Beautiful_Habit_Tracker_2026.xlsx'
    workbook = xlsxwriter.Workbook(file_name)
    ws = workbook.add_worksheet('My Dashboard')

    # --- 1. THE COLOR PALETTE & FORMATS ---
    bg_color = '#F8F9F9'
    header_color = '#2C3E50' # Dark Slate
    accent_color = '#3498DB' # Modern Blue
    
    ws.hide_gridlines(2) 

    # Custom Formats
    title_fmt = workbook.add_format({'bold': True, 'font_size': 26, 'font_name': 'Segoe UI', 'font_color': header_color})
    quote_fmt = workbook.add_format({'italic': True, 'font_size': 10, 'font_name': 'Segoe UI', 'font_color': '#7F8C8D'})
    label_fmt = workbook.add_format({'font_name': 'Segoe UI', 'font_size': 11, 'font_color': '#566573', 'valign': 'vcenter'})
    dropdown_fmt = workbook.add_format({'bg_color': '#FFFFFF', 'border': 2, 'border_color': accent_color, 'align': 'center', 'valign': 'vcenter', 'font_name': 'Segoe UI', 'bold': True})
    
    header_fmt = workbook.add_format({
        'bold': True, 'font_name': 'Segoe UI', 'font_color': '#FFFFFF',
        'bg_color': header_color, 'align': 'center', 'valign': 'vcenter', 'border': 1
    })
    
    date_row_fmt = workbook.add_format({'font_name': 'Segoe UI', 'border': 1, 'border_color': '#D5DBDB', 'align': 'left', 'bg_color': '#FFFFFF'})
    check_fill_fmt = workbook.add_format({'bg_color': '#D4EFDF'}) 

    # --- 2. LAYOUT DESIGN ---
    ws.set_column('A:A', 2)    # Margin
    ws.set_column('B:B', 18)   # Date Column
    ws.set_column('C:J', 14)   # Habit Columns
    ws.set_column('K:K', 5)    # Divider
    ws.set_column('L:M', 22)   # Dashboard Columns
    
    # Title & Month Selector (No image this time!)
    ws.write('B2', '✨ HABIT MASTERY 2026', title_fmt)
    
    months = ['January', 'February', 'March', 'April', 'May', 'June', 
              'July', 'August', 'September', 'October', 'November', 'December']
    
    ws.write('B4', 'CHOOSE MONTH:', label_fmt)
    ws.write('C4', 'January', dropdown_fmt)
    ws.data_validation('C4', {'validate': 'list', 'source': months})
    
    # --- 3. DYNAMIC QUOTES ---
    # This formula changes the quote based on the month selected in C4
    quotes = [
        "New year, new discipline.", "Consistency is key.", "Small steps every day.",
        "Don't stop until you're proud.", "Action is the foundational key.", "Focus on the goal.",
        "Discipline is freedom.", "Keep showing up.", "Success is a habit.",
        "Make it happen.", "Stay hungry, stay foolish.", "Finish the year strong."
    ]
    quote_formula = f'=CHOOSE(MATCH(C4, {{"' + '","'.join(months) + '"}}, 0), "' + '","'.join(quotes) + '")'
    ws.write_formula('B3', quote_formula, quote_fmt)

    # Hidden helper for month logic
    ws.write('Z1', '=MATCH(C4, {"' + '","'.join(months) + '"}, 0)')

    # --- 4. THE TRACKING TABLE ---
    habits = ['Gym', 'Reading', 'Meditation', 'Hydration', 'No Sugar', 'Coding', 'Sleep', 'Journal']
    
    ws.write(6, 1, 'DATE', header_fmt)
    for i, habit in enumerate(habits):
        ws.write(6, i + 2, habit.upper(), header_fmt)
    ws.set_row(6, 30) 

    for i in range(31):
        row = i + 7
        ws.set_row(row, 22) 
        date_formula = f'=IF(MONTH(DATE(2026, $Z$1, {i+1}))=$Z$1, DATE(2026, $Z$1, {i+1}), "")'
        ws.write_formula(row, 1, date_formula, date_row_fmt)
        
        for col in range(2, len(habits) + 2):
            ws.insert_checkbox(row, col, False)

    # Conditional Formatting
    ws.conditional_format(7, 2, 37, 9, {
        'type': 'formula',
        'criteria': '=AND(C8=TRUE, $B8<>"")',
        'format': check_fill_fmt
    })

    # --- 5. THE DASHBOARD ---
    ws.merge_range('L7:M7', 'MONTHLY PROGRESS', header_fmt)
    
    for i, habit in enumerate(habits):
        r = i + 8
        ws.write(r, 11, habit, label_fmt)
        col_letter = chr(67 + i)
        perc_formula = f'=COUNTIF({col_letter}8:{col_letter}38, TRUE)/DAY(EOMONTH(DATE(2026, $Z$1, 1), 0))'
        ws.write_formula(r, 12, perc_formula, workbook.add_format({'num_format': '0%', 'align': 'right', 'font_name': 'Segoe UI', 'bold': True}))

    # Clean Chart
    chart = workbook.add_chart({'type': 'bar'})
    chart.add_series({
        'name': 'Progress',
        'categories': ['My Dashboard', 8, 11, 8 + len(habits)-1, 11],
        'values':     ['My Dashboard', 8, 12, 8 + len(habits)-1, 12],
        'fill':       {'color': accent_color},
    })
    chart.set_title({'name': 'Consistency Score'})
    chart.set_legend({'none': True})
    chart.set_chartarea({'border': {'none': True}})
    ws.insert_chart('L18', chart, {'x_scale': 1.1, 'y_scale': 1.1})

    workbook.close()
    print("Beautiful Tracker Created! (No image errors this time)")

if __name__ == "__main__":
    create_beautiful_tracker()