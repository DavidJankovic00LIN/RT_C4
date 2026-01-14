
uint8_t winning_rt()
{
    int row, col, idx;
    unsigned char s;


    // HORIZONTAL 
  
    row = 0;
H_ROW_CHECK:
    if (row < 6) goto H_COL_INIT;
    goto V_COL_INIT;

H_COL_INIT:
    col = 0;
H_COL_CHECK:
    if (col <= 3) goto H_CHECK4;
    row = row + 1;
    goto H_ROW_CHECK;

H_CHECK4:
    idx = row * 7 + col;
    s = input[idx]; 
    if (s != ' ' &&
        s == input[idx + 1] &&
        s == input[idx + 2] &&
        s == input[idx + 3])
    {
        return (s == 'X') ? 1 : 2;
    }
    col = col + 1;
    goto H_COL_CHECK;

    // 2) VERTICAL (col: 0..6, row: 0..2)

V_COL_INIT:
    col = 0;
V_COL_CHECK:
    if (col < 7) goto V_ROW_INIT;
    goto D1_ROW_INIT;

V_ROW_INIT:
    row = 0;
V_ROW_CHECK:
    if (row <= 2) goto V_CHECK4;
    col = col + 1;
    goto V_COL_CHECK;

V_CHECK4:
    idx = row * 7 + col;
    s = input[idx];
    if (s != ' ' &&
        s == input[(row + 1) * 7 + col] &&
        s == input[(row + 2) * 7 + col] &&
        s == input[(row + 3) * 7 + col])
    {
        return (s == 'X') ? 1 : 2;
    }
    row = row + 1;
    goto V_ROW_CHECK;

    // 3) DIAGONAL "\"
    
D1_ROW_INIT:
    row = 0;
D1_ROW_CHECK:
    if (row <= 2) goto D1_COL_INIT;
    goto D2_ROW_INIT;

D1_COL_INIT:
    col = 0;
D1_COL_CHECK:
    if (col <= 3) goto D1_CHECK4;
    row = row + 1;
    goto D1_ROW_CHECK;

D1_CHECK4:
    idx = row * 7 + col;
    s = input[idx];
    if (s != ' ' &&
        s == input[(row + 1) * 7 + (col + 1)] &&
        s == input[(row + 2) * 7 + (col + 2)] &&
        s == input[(row + 3) * 7 + (col + 3)])
    {
        return (s == 'X') ? 1 : 2;
    }
    col = col + 1;
    goto D1_COL_CHECK;


    // 4) DIAGONAL /
 
D2_ROW_INIT:
    row = 0;
D2_ROW_CHECK:
    if (row <= 2) goto D2_COL_INIT;
    goto EMPTY_SCAN_INIT;

D2_COL_INIT:
    col = 3;
D2_COL_CHECK:
    if (col < 7) goto D2_CHECK4;
    row = row + 1;
    goto D2_ROW_CHECK;

D2_CHECK4:
    idx = row * 7 + col;
    s = input[idx];
    if (s != ' ' &&
        s == input[(row + 1) * 7 + (col - 1)] &&
        s == input[(row + 2) * 7 + (col - 2)] &&
        s == input[(row + 3) * 7 + (col - 3)])
    {
        return (s == 'X') ? 1 : 2;
    }
    col = col + 1;
    goto D2_COL_CHECK;

    
    //  provera praznih

EMPTY_SCAN_INIT:
    idx = 0;
EMPTY_SCAN_CHECK:
    if (idx < 42) goto EMPTY_SCAN_BODY;
    goto DRAW_RETURN;

EMPTY_SCAN_BODY:
    s = input[idx];
    if (s == ' ') {
        return 0; 
    }
    idx = idx + 1;
    goto EMPTY_SCAN_CHECK;

  
    //nereseno
   
DRAW_RETURN:
    return 3;
}
