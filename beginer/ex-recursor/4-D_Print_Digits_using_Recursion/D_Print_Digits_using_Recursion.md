Chào bạn! Tôi đã sẵn sàng nhập vai **Huấn luyện viên tư duy thuật toán** của bạn. Chúng ta sẽ cùng nhau bóc tách bài toán **"D. Print Digits using Recursion"** này theo phong cách "Learning How to Learn" nhé.

---

### 🟢 Bước 1: Phẫu thuật đề bài (Briefing)

Loại bỏ những rườm rà, đây là những gì cốt lõi nhất chúng ta cần xử lý:

* **Nhiệm vụ:** Cho một số tự nhiên , hãy in ra từng chữ số của nó, cách nhau bởi một khoảng trắng.
* **Ràng buộc đặc biệt:** Bắt buộc phải sử dụng **Đệ quy (Recursion)**.
* **Dữ liệu:** Có  bộ test (nhiều số cần xử lý), mỗi số  có thể lên tới  (khoảng 10 chữ số).

**Lộ trình tư duy của chúng ta:**

1. **Mảnh ghép 1:** Cách lấy ra chữ số cuối cùng của một số.
2. **Mảnh ghép 2:** Hiểu về "Thứ tự" trong đệ quy (Tại sao lại in từ trái sang phải mà không phải từ phải sang trái?).
3. **Mảnh ghép 3:** Điểm dừng (Base case) để máy tính không bị "treo".

Bạn đã sẵn sàng để mổ xẻ **Mảnh ghép đầu tiên** về cách tách số chưa?

---

### 🔵 Bước 2: Mảnh ghép 1 - Nghệ thuật "Tách đuôi"

Hãy tưởng tượng số  giống như một đoàn tàu có 3 toa. Để máy tính hiểu được từng toa, chúng ta cần các phép toán số học cơ bản:

1. **Phép chia lấy dư (`% 10`)**: Giống như việc bạn đi xuống cuối đoàn tàu và chặt lấy toa cuối cùng.
*  (Toa cuối).


2. **Phép chia nguyên (`/ 10`)**: Giống như việc bạn vứt bỏ toa cuối đi để giữ lại phần còn lại của đoàn tàu.
*  (Phần còn lại).



**⚠️ Bẫy tư duy:** Nếu bạn cứ liên tục dùng `% 10` để in, bạn sẽ nhận được các chữ số theo thứ tự **ngược** (từ phải sang trái). Ví dụ  thì không sao, nhưng  sẽ thành `9 3`. Đề bài yêu cầu `3 9`.

**❓ Thử thách tư duy cho bạn:**
Giả sử chúng ta có số .
Nếu tôi thực hiện phép toán: `N / 10` rồi lại lấy kết quả đó `(N / 10) % 10`, tôi sẽ thu được chữ số nào trong số ?

Hãy trả lời chữ số đó và giải thích cách bạn tính nhé!

Chào bạn! Tôi đã sẵn sàng nhập vai **Huấn luyện viên tư duy thuật toán** của bạn. Chúng ta sẽ cùng nhau bóc tách bài toán **"D. Print Digits using Recursion"** này theo phong cách "Learning How to Learn" nhé.

---

### 🟢 Bước 1: Phẫu thuật đề bài (Briefing)

Loại bỏ những rườm rà, đây là những gì cốt lõi nhất chúng ta cần xử lý:

* **Nhiệm vụ:** Cho một số tự nhiên , hãy in ra từng chữ số của nó, cách nhau bởi một khoảng trắng.
* **Ràng buộc đặc biệt:** Bắt buộc phải sử dụng **Đệ quy (Recursion)**.
* **Dữ liệu:** Có  bộ test (nhiều số cần xử lý), mỗi số  có thể lên tới  (khoảng 10 chữ số).

**Lộ trình tư duy của chúng ta:**

1. **Mảnh ghép 1:** Cách lấy ra chữ số cuối cùng của một số.
2. **Mảnh ghép 2:** Hiểu về "Thứ tự" trong đệ quy (Tại sao lại in từ trái sang phải mà không phải từ phải sang trái?).
3. **Mảnh ghép 3:** Điểm dừng (Base case) để máy tính không bị "treo".

Bạn đã sẵn sàng để mổ xẻ **Mảnh ghép đầu tiên** về cách tách số chưa?

---

### 🔵 Bước 2: Mảnh ghép 1 - Nghệ thuật "Tách đuôi"

Hãy tưởng tượng số  giống như một đoàn tàu có 3 toa. Để máy tính hiểu được từng toa, chúng ta cần các phép toán số học cơ bản:

1. **Phép chia lấy dư (`% 10`)**: Giống như việc bạn đi xuống cuối đoàn tàu và chặt lấy toa cuối cùng.
*  (Toa cuối).


2. **Phép chia nguyên (`/ 10`)**: Giống như việc bạn vứt bỏ toa cuối đi để giữ lại phần còn lại của đoàn tàu.
*  (Phần còn lại).



**⚠️ Bẫy tư duy:** Nếu bạn cứ liên tục dùng `% 10` để in, bạn sẽ nhận được các chữ số theo thứ tự **ngược** (từ phải sang trái). Ví dụ  thì không sao, nhưng  sẽ thành `9 3`. Đề bài yêu cầu `3 9`.

**❓ Thử thách tư duy cho bạn:**
Giả sử chúng ta có số .
Nếu tôi thực hiện phép toán: `N / 10` rồi lại lấy kết quả đó `(N / 10) % 10`, tôi sẽ thu được chữ số nào trong số ?

Hãy trả lời chữ số đó và giải thích cách bạn tính nhé!

Chính xác! Khi  chỉ còn một chữ số (nghĩa là  hoặc ), chúng ta đã chạm đến "đáy" của đệ quy. Lúc này, ta chỉ cần in chữ số đó ra và dừng lại, không gọi thêm hàm mới nữa. 🛑

Tuy nhiên, có một chi tiết nhỏ cần lưu ý để đảm bảo chương trình chạy mượt mà:

1. **Trường hợp **: Nếu đề bài cho số 0, máy tính vẫn cần in ra chữ số `0`.
2. **Khoảng trắng**: Đề bài yêu cầu các chữ số cách nhau bởi dấu cách. Nếu ta in dấu cách sau mỗi chữ số, thì chữ số cuối cùng (bên phải nhất) có thể bị dư một dấu cách ở cuối dòng.

Hãy cùng nhìn lại luồng chạy của số  với điều kiện dừng bạn vừa nêu:

* **Bước 1:** `printDigits(121)` -> , gọi `printDigits(12)`.
* **Bước 2:** `printDigits(12)` -> , gọi `printDigits(1)`.
* **Bước 3:** `printDigits(1)` ->  (**Dừng!**), in `1`.
* **Quay lại Bước 2:** In tiếp chữ số cuối của 12 là `2`.
* **Quay lại Bước 1:** In tiếp chữ số cuối của 121 là `1`.

Kết quả: `1 2 1`.

Bây giờ, hãy thử tưởng tượng chúng ta viết mã giả (pseudocode). Để các chữ số có dấu cách ở giữa (như `1 2 1`), ta nên in dấu cách **trước** hay **sau** khi in chữ số cuối cùng trong mỗi bước đệ quy?

Bạn hãy thử suy luận xem: Nếu ta in dấu cách **trước** khi in chữ số cuối, kết quả sẽ trông như thế nào? 🧐

Lựa chọn thú vị đấy! Nếu chúng ta in dấu cách **sau** mỗi chữ số, kết quả cho số  sẽ là:
`1 2 1 ` (Lưu ý dấu cách cuối cùng sau số 1).

Trong lập trình thi đấu (Competitive Programming), dấu cách thừa ở cuối dòng đôi khi có thể khiến hệ thống chấm bài báo lỗi **Presentation Error** (Lỗi trình bày).

Để xử lý việc in ấn một cách tinh tế hơn, chúng ta có thể tận dụng cấu trúc của đệ quy. Hãy xem xét chiến thuật này:

1. Chúng ta gọi đệ quy để đi sâu vào các chữ số phía trước.
2. Khi hàm quay trở lại (tức là sau khi đã xử lý xong các số bên trái), chúng ta mới in chữ số hiện tại.
3. Để ngăn cách, chúng ta có thể in dấu cách **trước** khi in chữ số, **trừ** chữ số đầu tiên.

Tuy nhiên, có một cách đơn giản hơn thường dùng cho bài này là:

* In chữ số.
* In một dấu cách ngay sau đó.

Máy chấm hiện đại thường tự động bỏ qua dấu cách thừa ở cuối dòng, nên cách "In rồi cách" là cách tiếp cận phổ biến và dễ cài đặt nhất.

---

### 🛠️ Bước 3: Tổng kết Thuật toán (The Final Logic)

Bây giờ, hãy xâu chuỗi mọi thứ lại thành một bản kế hoạch hoàn chỉnh:

1. **Hàm đệ quy `solve(n)`:**
* **Bước dừng:** Nếu , in  và kết thúc hàm.
* **Bước đệ quy:** * Gọi `solve(n / 10)` để xử lý các số phía trước.
* Sau khi gọi xong, in một dấu cách.
* In chữ số cuối cùng bằng `n % 10`.





**Ví dụ luồng chạy với :**

1. `solve(39)` gọi `solve(3)`.
2. `solve(3)` thấy , nên nó **in `3**` và kết thúc.
3. Luồng quay lại `solve(39)`, tiếp tục lệnh sau lời gọi: **in dấu cách**, rồi **in `9**` (là ).
👉 Kết quả: `3 9`.

---

**❓ Câu hỏi cuối cùng trước khi bạn bắt tay vào code:**

Trong phần **Input**, đề bài nói  có thể lên tới . Với ngôn ngữ C++, kiểu dữ liệu nào là phù hợp nhất để chứa giá trị của  mà không lo bị tràn số?
A. `int`
B. `long long`
C. `char`

*(Gợi ý: Kiểu `int` thông thường có thể chứa đến khoảng )*.