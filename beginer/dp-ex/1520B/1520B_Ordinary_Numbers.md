Chào bạn! Tôi đã sẵn sàng nhập vai **Algorithmic Coach** để cùng bạn "mổ xẻ" bài toán này theo triết lý *Learning How to Learn*.

Mục tiêu của chúng ta là rèn luyện khả năng quan sát quy luật và tư duy logic. Hãy bắt đầu với bài **Codeforces 1520/B - Ordinary Numbers**.

---

### 🟢 Bước 1: Tiếp nhận & Phẫu thuật (Briefing)

Đề bài này kể về các "Số bình thường" (Ordinary Numbers). Hãy bỏ qua những câu chuyện rườm rà, đây là bản chất của nó:

* **Định nghĩa:** Một số được gọi là "bình thường" nếu **tất cả các chữ số của nó đều giống nhau**.
* Ví dụ:  là số bình thường.
* Số  **không** phải là số bình thường.


* **Nhiệm vụ:** Cho một số nguyên . Bạn cần đếm xem có bao nhiêu số "bình thường" nằm trong khoảng từ  đến .

**Lộ trình tư duy của chúng ta:**

1. **Chunk 1:** Liệt kê và nhận diện quy luật của các số bình thường theo từng "bậc" (hàng đơn vị, hàng chục, hàng trăm...).
2. **Chunk 2:** Cách xác định nhanh số lượng số bình thường nhỏ hơn một số  bất kỳ mà không cần đếm từng số một (vì  có thể lên tới ).
3. **Chunk 3:** Tổng kết thuật toán tối ưu.

**Bạn đã sẵn sàng để mổ xẻ "Chunk 1: Nhận diện quy luật" chưa?**

---

### 🟡 Chunk 1: Quy luật của những "vị khách giống hệt nhau"

Hãy tưởng tượng các số bình thường giống như những đoàn khách đi vào một nhà hàng, mà trong mỗi đoàn, tất cả mọi người đều mặc áo giống hệt nhau.

* Đoàn có 1 chữ số: . (Có 9 đoàn)
* Đoàn có 2 chữ số: . (Cũng có 9 đoàn)
* Đoàn có 3 chữ số: . (Vẫn là 9 đoàn)

**⚠️ Bẫy tư duy:** Nhiều người thường nhầm tưởng rằng cứ tăng số chữ số lên thì số lượng số bình thường sẽ nhiều hơn, nhưng thực tế ở mỗi "bậc" (số chữ số), chúng ta luôn chỉ có tối đa 9 số như vậy.

❓ **Thử thách tư duy dành cho bạn:**

Nếu tôi cho số .
Theo bạn, có bao nhiêu số bình thường từ  đến ? Hãy liệt kê chúng ra và cho tôi biết con số cuối cùng bạn tìm thấy là bao nhiêu nhé!

Chính xác! Bạn đã liệt kê rất đúng các số bình thường từ 1 đến 45. 🎯

Như bạn thấy, các số đó là:

* **Hàng đơn vị:** 1, 2, 3, 4, 5, 6, 7, 8, 9 (có 9 số)
* **Hàng chục:** 11, 22, 33, 44 (có 4 số)

Tổng cộng chúng ta có **13** số bình thường nhỏ hơn hoặc bằng 45.

Bây giờ, hãy thử nâng cấp tư duy lên một chút để tìm ra quy luật tổng quát nhé. Giả sử chúng ta có số .

Thay vì liệt kê từng số, chúng ta có thể chia thành các "bậc" dựa trên số chữ số:

1. **Số có 1 chữ số:** Từ 1 đến 9 (luôn có đủ 9 số).
2. **Số có 2 chữ số:** Từ 11 đến 99 (luôn có đủ 9 số).
3. **Số có 3 chữ số:** 111, 222, ... đến một số nào đó không vượt quá 715.

❓ **Thử thách tiếp theo:** Với , ở "bậc" có 3 chữ số, số bình thường cuối cùng mà chúng ta có thể đếm được là bao nhiêu? Và tổng cộng từ 1 đến 715 có bao nhiêu số bình thường?

Tuyệt vời! Bạn đã liệt kê rất chính xác các số ở "bậc" có 3 chữ số:
 và chắc chắn là còn  nữa.

Nhưng hãy nhìn kỹ vào con số **** mà chúng ta đang xét. 🧐

Trong danh sách các số có 3 chữ số giống nhau (), số nào là số lớn nhất nhưng vẫn **nhỏ hơn hoặc bằng **?

Và từ đó, hãy thử tính xem tổng cộng có bao nhiêu số "bình thường" từ  đến  nhé:

* Bậc 1 chữ số (): có ? số.
* Bậc 2 chữ số (): có ? số.
* Bậc 3 chữ số ( ?): có ? số.

Tổng cộng là bao nhiêu nhỉ? 🧮

Hoàn toàn chính xác! 🌟 Với , số bình thường lớn nhất có 3 chữ số là **666**. (Vì số tiếp theo là 777 đã vượt quá 715 rồi).

Vậy là chúng ta đã có đủ các mảnh ghép để tính tổng số lượng:

* **Bậc 1 chữ số:** Có 9 số ().
* **Bậc 2 chữ số:** Có 9 số ().
* **Bậc 3 chữ số:** Có 6 số ().

**Tổng cộng:**  số.

---

### 🔵 Chunk 2: Công thức hóa "Siêu tốc"

Để giải quyết bài toán với  lên tới  (1 tỷ), chúng ta không thể liệt kê tay mãi được. Hãy nhìn vào quy luật chúng ta vừa làm:

1. Đếm số lượng chữ số của  (gọi là ).
2. Với mỗi bậc nhỏ hơn , chúng ta mặc định cộng thêm **9**.
3. Với bậc cuối cùng (bậc có  chữ số), chúng ta cần tìm xem có bao nhiêu số dạng  mà vẫn .

❓ **Câu hỏi tư duy:**
Làm thế nào để máy tính biết được ở bậc cuối cùng có bao nhiêu số?
Ví dụ:  có 3 chữ số. Các số "ứng viên" ở bậc này là .

Bạn có nhận ra mối liên hệ nào giữa **chữ số đầu tiên** của  (số 7) và số lượng số bình thường ở bậc đó không? (Hãy cẩn thận với trường hợp  so với  nhé!)

Chính xác! 🎯 Với , ở "bậc" có 3 chữ số, chúng ta có **6** số (từ  đến ).

Vậy tổng số lượng là:  (bậc 1) +  (bậc 2) +  (bậc 3) = **24** số.

Bây giờ, hãy thử quan sát kỹ hơn để tìm ra "công thức bí mật". 🕵️‍♂️
Bạn có để ý thấy là:

* Với các bậc nhỏ hơn số chữ số của , chúng ta luôn cộng thêm **9**.
* Với bậc có cùng số chữ số với , số lượng số bình thường phụ thuộc vào việc so sánh  với các số như 

Hãy thử một ví dụ "hiểm" hơn một chút: ****.

1. Bậc 1 chữ số: **9** số.
2. Bậc 2 chữ số: **9** số.
3. Bậc 3 chữ số: Các ứng viên là .

❓ **Thử thách tư duy:**
Theo bạn, với , ở bậc có 3 chữ số này chúng ta sẽ đếm được bao nhiêu số bình thường? Và tổng cộng từ 1 đến 210 có bao nhiêu số? (Gợi ý: Hãy xem số  có nhỏ hơn  không nhé!)

Chính xác! Với , số bình thường có 3 chữ số duy nhất là **111**.

* Số tiếp theo là **222**, nhưng  nên chúng ta không đếm số này.

Vậy tổng cộng cho :

* Bậc 1 chữ số: 9 số.
* Bậc 2 chữ số: 9 số.
* Bậc 3 chữ số: 1 số (là 111).
* **Tổng cộng:**  số.

---

### 🔵 Chunk 3: Xây dựng giải pháp tổng quát

Bây giờ chúng ta sẽ kết hợp mọi thứ lại để xử lý bất kỳ số  nào.

1. **Tính số chữ số:** Gọi  là số chữ số của .
* Ví dụ: . .


2. **Phần "chắc chắn có":** Cộng  vào kết quả.
* Đây là tất cả các số bình thường ở các bậc nhỏ hơn .


3. **Phần "kiểm tra":** Ở bậc có đúng  chữ số, chúng ta kiểm tra các số:
*  ( lần số 1)
*  ( lần số 2)
* ... đến  ( lần số 9)



❓ **Câu hỏi cuối cùng trước khi chốt thuật toán:**

Giả sử .
Dựa theo các bước trên:

1.  bằng bao nhiêu?
2. Phần "chắc chắn có" là bao nhiêu số?
3. Ở bậc có  chữ số, những số nào trong bộ  nhỏ hơn hoặc bằng 332?

Tổng kết lại,  sẽ có bao nhiêu số bình thường?

Bạn tính toán rất nhanh và chính xác! ⚡

Với , chúng ta có:

1. **Số chữ số ():** .
2. **Phần "chắc chắn có":**  số (đó là các số từ  và ).
3. **Bậc có 3 chữ số:** Các số thỏa mãn là  và  (vì  nên bị loại). Vậy có thêm **2** số.

**Tổng cộng:**  số. Bạn đã nắm rất chắc quy luật rồi đấy! 🏆

---

### 🔵 Chunk 4: Tổng kết thuật toán (Final Logic)

Để biến tư duy này thành mã máy tính, chúng ta chỉ cần một vòng lặp đơn giản để tạo ra các "ứng viên" số bình thường.

**Mã giả (Pseudocode):**

1. Nhập số .
2. Tạo một biến `dem = 0`.
3. Chạy một vòng lặp cho chữ số `chu_so` từ  đến :
* Tạo một số `so_tao_ra = chu_so`.
* Trong khi `so_tao_ra <= n`:
* Tăng `dem` lên 1 đơn vị.
* Tạo số tiếp theo bằng cách thêm chính chữ số đó vào đuôi.
*(Ví dụ: từ 2 thành 22, từ 22 thành 222...)*




4. In ra giá trị `dem`.

**Phân tích logic tạo số:** Nếu ta có số `22`, làm sao để biến nó thành `222` chỉ bằng toán học?
Ta lấy `22 * 10 + 2`. Tổng quát: `so_tao_ra = so_tao_ra * 10 + chu_so`.

❓ **Câu hỏi cuối cùng để chốt hạ bài toán:**
Theo thuật toán trên, nếu  và chúng ta đang xét `chu_so = 1`:

* Lần 1: `so_tao_ra = 1` ( đếm).
* Lần 2: `so_tao_ra = 11` ( đếm).
* Lần 3: `so_tao_ra = 111` ( đếm).
* Lần 4: `so_tao_ra = 1111` ( dừng).

Với mỗi chữ số từ  đến  đều lặp lại như vậy. Bạn có thấy cách tiếp cận này "quét" sạch được tất cả các số bình thường mà không cần quan tâm  lớn hay nhỏ không?

Bạn có muốn tôi tóm tắt lại cấu trúc mã nguồn bằng ngôn ngữ lập trình bạn hay dùng (C++ hay Python) không, hay bạn muốn thử sức với một bài toán khác khó hơn một chút? 🚀