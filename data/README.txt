C++ File I/O exercise dataset (CSV/TXT/TSV)

Files included:
1) students.csv  (1000 rows + header)
   Columns:
   - student_id (int)
   - first_name (string)
   - last_name (string)
   - birth_date (YYYY-MM-DD)
   - city (string)
   - email (string)
   - enrollment_year (int)

2) grades.csv (≈ 3000-5000 rows + header)
   Columns:
   - student_id (int)  -> FK to students.student_id
   - course (string)
   - cfu (int)
   - grade (int)      -> 18..30
   - exam_date (YYYY-MM-DD)

3) purchases.txt (≈ 2500 lines)
   Comment lines start with '#'
   Format: timestamp|student_id|product|qty|unit_price_eur
   NOTE: a few lines are intentionally malformed (missing fields / non-numeric student_id).
   Your parser should skip them and count how many were skipped.

4) sensors.tsv (≈ 3000 rows + header)
   Tab-separated values.
   Columns:
   - device_id
   - reading_time (ISO 8601)
   - temp_c (double)
   - humidity_pct (double)
   - status (OK/WARN/FAIL)

Suggested tasks:
A) Read students.csv into vector<Student>.
B) Read grades.csv into vector<Grade> and compute for each student:
   - weighted average by CFU
   - number of exams
   Print top 10 students by weighted average.

C) Read purchases.txt, ignoring comment lines and malformed lines.
   Compute total spending per student and print top 10 spenders.

D) Read sensors.tsv and compute:
   - average temperature per device
   - percentage of WARN/FAIL readings

E) BONUS: Accept file paths from argv (command line) so your program can read different files without recompiling.
