Dưới đây là danh sách 20 bài tập Codeforces được tuyển chọn kỹ lưỡng thuộc dạng toán **Simulation (Mô phỏng)** và **Constructive Algorithms**, phù hợp để giải quyết bằng vòng lặp `while` ở mức rank Newbie (800 - 900 Elo).

Các bài tập này tập trung vào việc mô phỏng các quá trình tăng trưởng, tích lũy, hoặc biến đổi trạng thái theo thời gian.

---

### 1. Bear and Big Brother (791A)

* **Link:** [Codeforces 791A](https://codeforces.com/problemset/problem/791/A)
* **Tóm tắt:** Gấu Limak nặng  và Bob nặng  (). Sau mỗi năm, Limak tăng cân gấp 3, Bob tăng cân gấp 2. Hỏi sau bao nhiêu năm Limak sẽ nặng hơn Bob?
* **Hướng giải quyết (`while`):**
* Sử dụng biến đếm `nam = 0`.
* Điều kiện lặp: `while (a <= b)`.
* Trong vòng lặp: Cập nhật ,  và tăng `nam` lên 1.



### 2. Vanya and Cubes (492A)

* **Link:** [Codeforces 492A](https://codeforces.com/problemset/problem/492/A)
* **Tóm tắt:** Xây kim tự tháp từ  khối lập phương. Tầng 1 cần 1 khối, tầng 2 cần 3 khối (), tầng  cần tổng các số từ 1 đến . Tìm chiều cao tối đa xây được.
* **Hướng giải quyết (`while`):**
* Dùng `while` để trừ dần số khối  cho đến khi không đủ xây tầng tiếp theo.
* Biến `h` (chiều cao), `cnt` (gạch tầng hiện tại). Mỗi vòng lặp cập nhật `h++`, `cnt += h`, và kiểm tra `n >= cnt`.



### 3. Wrong Subtraction (977A)

* **Link:** [Codeforces 977A](https://codeforces.com/problemset/problem/977/A)
* **Tóm tắt:** Giảm số  đi  lần. Quy tắc: nếu tận cùng là 0 thì chia 10, nếu khác 0 thì trừ 1.
* **Hướng giải quyết (`while`):**
* Điều kiện lặp: `while (k > 0)`.
* Trong vòng lặp: Kiểm tra `n % 10`. Nếu bằng 0 thì `n /= 10`, ngược lại `n--`. Sau đó giảm `k--`.



### 4. Elephant (617A)

* **Link:** [Codeforces 617A](https://codeforces.com/problemset/problem/617/A)
* **Tóm tắt:** Con voi cần đi đến điểm . Mỗi bước đi được 1, 2, 3, 4 hoặc 5 bước. Tìm số bước tối thiểu.
* **Hướng giải quyết (`while`):**
* Mô phỏng bước đi tham lam (luôn bước dài nhất).
* Điều kiện lặp: `while (x > 0)`.
* Trong vòng lặp: Trừ  đi 5 (hoặc phần dư còn lại) và tăng biến đếm bước.



### 5. Soldier and Bananas (546A)

* **Link:** [Codeforces 546A](https://codeforces.com/problemset/problem/546/A)
* **Tóm tắt:** Mua  quả chuối. Quả thứ  giá . Tính số tiền phải vay.
* **Hướng giải quyết (`while`):**
* Mô phỏng việc mua từng quả.
* Biến `i = 1`. Điều kiện `while (i <= w)`.
* Cộng dồn giá tiền `total += i * k`. Tăng `i++`.



### 6. Tram (116A)

* **Link:** [Codeforces 116A](https://codeforces.com/problemset/problem/116/A)
* **Tóm tắt:** Tàu điện qua  trạm. Mỗi trạm có người lên và xuống. Tìm sức chứa tối thiểu cần thiết (số khách cực đại tại một thời điểm).
* **Hướng giải quyết (`while`):**
* Duyệt qua các trạm bằng `while (i < n)`.
* Cập nhật số khách hiện tại: `curr = curr - ra + vao`.
* So sánh và cập nhật `max_capacity`.



### 7. Beautiful Year (271A)

* **Link:** [Codeforces 271A](https://codeforces.com/problemset/problem/271/A)
* **Tóm tắt:** Tìm năm nhỏ nhất lớn hơn năm  đã cho mà các chữ số của nó đôi một khác nhau.
* **Hướng giải quyết (`while`):**
* Điều kiện lặp: `while (true)`.
* Tăng `y++`. Trong vòng lặp, tách các chữ số của `y` ra và kiểm tra trùng lặp. Nếu không trùng, in `y` và `break` (thoát).



### 8. Near Lucky Number (110A)

* **Link:** [Codeforces 110A](https://codeforces.com/problemset/problem/110/A)
* **Tóm tắt:** Đếm số lượng chữ số may mắn (4 và 7) trong số nguyên . Kiểm tra xem số lượng đó có phải số may mắn không.
* **Hướng giải quyết (`while`):**
* Duyệt từng chữ số của .
* Điều kiện `while (n > 0)`.
* Lấy số cuối `d = n % 10`, kiểm tra `d == 4 |



| d == 7`, sau đó `n /= 10`.

### 9. Word (59A)

* **Link:** [Codeforces 59A](https://codeforces.com/problemset/problem/59/A)
* **Tóm tắt:** Đếm số chữ hoa và thường. Nếu hoa > thường thì in toàn bộ hoa, ngược lại in thường.
* **Hướng giải quyết (`while`):**
* Dùng `while` duyệt chuỗi để đếm `upper` và `lower`.
* Dùng `while` duyệt lại lần nữa để in ra ký tự đã biến đổi.



### 10. Translation (41A)

* **Link:** [Codeforces 41A](https://codeforces.com/problemset/problem/41/A)
* **Tóm tắt:** Kiểm tra chuỗi  có phải là đảo ngược của chuỗi  không.
* **Hướng giải quyết (`while`):**
* Dùng 2 chỉ số: `i` chạy từ đầu , `j` chạy từ cuối .
* Điều kiện `while (i < s.length())`. So sánh `s[i]` và `t[j]`.



### 11. Anton and Danik (734A)

* **Link:** [Codeforces 734A](https://codeforces.com/problemset/problem/734/A)
* **Tóm tắt:** Đếm số trận thắng của Anton ('A') và Danik ('D'). So sánh xem ai thắng nhiều hơn.
* **Hướng giải quyết (`while`):**
* Duyệt chuỗi kết quả bằng `while`.
* Nếu gặp 'A' tăng biến `anton`, gặp 'D' tăng biến `danik`.



### 12. Queue at the School (266B)

* **Link:**([https://codeforces.com/problemset/problem/266/B](https://codeforces.com/problemset/problem/266/B))
* **Tóm tắt:** Hàng đợi có nam (B) và nữ (G). Mỗi giây, nếu B đứng trước G thì đổi chỗ. Mô phỏng sau  giây.
* **Hướng giải quyết (`while`):**
* Vòng lặp ngoài `while (t--)` đếm thời gian.
* Vòng lặp trong duyệt hàng đợi, tìm cặp "BG" để đổi thành "GB" (lưu ý tăng chỉ số để không đổi 1 người nhiều lần trong 1 giây).



### 13. In Search of an Easy Problem (1030A)

* **Link:** [Codeforces 1030A](https://codeforces.com/problemset/problem/1030/A)
* **Tóm tắt:** Khảo sát độ khó. Nếu có ít nhất 1 người nói khó (1) thì bài toán là KHÓ.
* **Hướng giải quyết (`while`):**
* Duyệt qua  ý kiến bằng `while`.
* Dùng biến cờ (flag). Nếu gặp số 1 thì bật cờ `is_hard = true`.



### 14. George and Accommodation (467A)

* **Link:** [Codeforces 467A](https://codeforces.com/problemset/problem/467/A)
* **Tóm tắt:** Đếm số phòng ký túc xá còn trống ít nhất 2 chỗ.
* **Hướng giải quyết (`while`):**
* Duyệt qua  phòng bằng `while`.
* Đọc `p` (đang ở) và `q` (sức chứa). Nếu `q - p >= 2` thì tăng biến đếm.



### 15. Stones on the Table (266A)

* **Link:** [Codeforces 266A](https://codeforces.com/problemset/problem/266/A)
* **Tóm tắt:** Đếm số lượng đá cần bỏ bớt để không có hai viên đá màu giống nhau nằm cạnh nhau.
* **Hướng giải quyết (`while`):**
* Duyệt chuỗi màu đá bằng `while (i < n - 1)`.
* So sánh `s[i]` và `s[i+1]`. Nếu giống nhau thì tăng biến đếm `remove`.



### 16. Magnets (344A)

* **Link:** [Codeforces 344A](https://codeforces.com/problemset/problem/344/A)
* **Tóm tắt:** Đếm số nhóm nam châm liên kết với nhau (do hút nhau 01-10). Nhóm mới hình thành khi cực thay đổi.
* **Hướng giải quyết (`while`):**
* Duyệt qua danh sách nam châm.
* Lưu giá trị trước đó `prev`. Nếu giá trị hiện tại khác `prev` thì tăng số nhóm.



### 17. Drinks (200B)

* **Link:**([https://codeforces.com/problemset/problem/200/B](https://codeforces.com/problemset/problem/200/B))
* **Tóm tắt:** Tính nồng độ phần trăm trung bình của cocktail từ  loại nước.
* **Hướng giải quyết (`while`):**
* Dùng `while` để cộng dồn tất cả các giá trị phần trăm đầu vào vào biến `sum`.
* Kết quả là `sum / n`.



### 18. Hulk (705A)

* **Link:** [Codeforces 705A](https://codeforces.com/problemset/problem/705/A)
* **Tóm tắt:** In ra chuỗi cảm xúc "I hate that I love that..." theo lớp .
* **Hướng giải quyết (`while`):**
* Biến đếm `i = 1`. Điều kiện `while (i <= n)`.
* Nếu `i` lẻ in "I hate", chẵn in "I love".
* Nếu `i < n` in thêm "that", ngược lại in "it".



### 19. Calculating Function (486A)

* **Link:** [Codeforces 486A](https://codeforces.com/problemset/problem/486/A)
* **Tóm tắt:** Tính .
* **Hướng giải quyết (`while`):**
* *Lưu ý:* Bài này nếu dùng `while` để cộng từng số sẽ bị quá thời gian (TLE) với  lớn.
* Tuy nhiên, để luyện tập logic mô phỏng cho  nhỏ: Dùng `while` kiểm tra tính chẵn lẻ của `i` để cộng hoặc trừ vào tổng. (Khuyến khích học sinh tìm công thức sau khi mô phỏng).



### 20. Police Recruits (427A)

* **Link:** [Codeforces 427A](https://codeforces.com/problemset/problem/427/A)
* **Tóm tắt:** Nhận sự kiện: số dương là tuyển cảnh sát, -1 là có tội phạm. Đếm số tội phạm không bị bắt (khi không có cảnh sát).
* **Hướng giải quyết (`while`):**
* Duyệt sự kiện bằng `while`.
* Dùng biến `officers`. Nếu gặp tuyển dụng: `officers++`.
* Nếu gặp tội phạm: Kiểm tra `if (officers > 0) officers--` ngược lại `untreated++`.