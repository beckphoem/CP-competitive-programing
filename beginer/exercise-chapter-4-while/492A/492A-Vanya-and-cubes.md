Chào mừng bạn đến với bài toán **Codeforces 492A - Vanya and Cubes**. Tôi là Coach Tư Duy của bạn.

Chúng ta sẽ không vội lao vào viết vòng lặp `for` hay `while` ngay. Hãy đặt bàn phím xuống và mổ xẻ logic của việc "xây kim tự tháp" trước đã.

---

### BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

**📝 Tóm tắt đề bài (Ngôn ngữ con người):**
Bạn có một đống khối lập phương (gọi tắt là gạch) với số lượng là . Bạn muốn xếp chúng thành một kim tự tháp cao nhất có thể.
Quy luật xếp:

* Tầng trên cùng (tầng 1): 1 viên.
* Tầng thứ 2:  viên.
* Tầng thứ 3:  viên.
* ...
* Tầng thứ :  viên.

**🗺️ Lộ trình tư duy:**

1. **Chunk 1:** Hiểu "giá tiền" của từng tầng (Mỗi tầng tốn bao nhiêu gạch?).
2. **Chunk 2:** Tính tổng "hóa đơn" (Tổng số gạch đã dùng để xây đến tầng hiện tại).
3. **Chunk 3:** Điểm dừng (Khi nào thì hết gạch?).

---

Bạn đã sẵn sàng chưa? Chúng ta bắt đầu với mảnh ghép đầu tiên nhé.

### BƯỚC 2: VÒNG LẶP TƯ DUY - CHUNK 1: GIÁ CỦA TỪNG TẦNG

**🧠 Logic (Explain):**
Hãy tưởng tượng mỗi tầng của kim tự tháp giống như một "bậc thang" tam giác.
Để xây tầng thứ , số gạch bạn cần không phải là một con số ngẫu nhiên, mà nó tuân theo quy tắc cộng dồn (Rolling sum).

* Tầng 1 (đỉnh): Cần 1 viên.
* Tầng 2: Cần số gạch của tầng 1 + thêm 2 viên nữa = 3 viên.
* Tầng 3: Cần số gạch của tầng 2 + thêm 3 viên nữa = 6 viên.

👉 **Ẩn dụ:** Hãy tưởng tượng số gạch cần cho tầng hiện tại giống như một "hòn tuyết lăn". Mỗi lần lăn xuống một tầng mới (tầng thứ ), hòn tuyết sẽ to thêm một lượng đúng bằng số thứ tự của tầng đó ().

**⚠️ Bẫy (Trap):**
Rất nhiều bạn nhầm lẫn giữa:

1. Số gạch của **riêng tầng đó**.
2. Tổng số gạch của **cả kim tự tháp**.
Ở Chunk này, chúng ta chỉ quan tâm đến số gạch của **riêng tầng đó** thôi.

**❓ Thử thách tư duy (Mental Check):**
Giả sử chúng ta đang muốn xây **Tầng thứ 4** (Level 4).
Dựa trên quy luật trên, chỉ riêng tầng thứ 4 này sẽ ngốn của bạn bao nhiêu viên gạch?

A. 4 viên
B. 6 viên
C. 10 viên

*Hãy chọn đáp án và giải thích ngắn gọn cách bạn tính ra nó.*


Tuyệt vời! Chính xác là **C. 10 viên**.
(Giải thích: Tầng 4 cần  viên, hoặc đơn giản là lấy số gạch tầng 3 là 6 viên cộng thêm 4).

Bạn đã nắm vững cách tính số gạch cho **một tầng**. Bây giờ chúng ta sang bước quan trọng tiếp theo.

---

### BƯỚC 2: VÒNG LẶP TƯ DUY - CHUNK 2: TÍNH TỔNG "HÓA ĐƠN" (TOTAL COST)

**🧠 Logic (Explain):**
Biết giá từng tầng rồi chưa đủ, giờ ta phải cộng dồn lại xem "tổng thiệt hại" để xây cả cái tháp là bao nhiêu.
Để sở hữu một kim tự tháp cao  tầng, bạn cần **Tổng số gạch** của tất cả các tầng cộng lại:
(Gạch Tầng 1) + (Gạch Tầng 2) + ... + (Gạch Tầng ).

👉 **Ẩn dụ:** Hãy tưởng tượng bạn đi siêu thị "Mua Tầng Tháp".

* Bạn nhặt Tầng 1 vào giỏ: Tốn 1 viên.
* Bạn nhặt Tầng 2 vào giỏ: Tốn thêm 3 viên nữa.
* ...
Số gạch thực sự biến mất khỏi kho của bạn là tổng số gạch trong cái giỏ đó.

**⚠️ Bẫy (Trap):**
Đây là cái bẫy lớn nhất của bài này! 🚨
Rất nhiều bạn nhầm lẫn lấy số gạch của **tầng đang xây** so sánh với .
SAI! Bạn phải lấy **TỔNG số gạch đã dùng từ đầu đến giờ** so sánh với .

**❓ Thử thách tư duy:**
Dựa vào các con số chúng ta đã tính:

* Tầng 1 tốn: 1 viên.
* Tầng 2 tốn: 3 viên.
* Tầng 3 tốn: 6 viên.

Câu hỏi: Nếu tôi muốn xây một kim tự tháp hoàn chỉnh cao **3 tầng**, **tổng cộng** tôi cần bao nhiêu viên gạch?

A. 6 viên (Vì tầng 3 tốn 6 viên)
B. 9 viên (1 + 2 + 6)
C. 10 viên (1 + 3 + 6)

*Hãy chọn đáp án đúng để chứng tỏ bạn không bị lừa nhé!*

Chính xác! Đáp án là **C. 10 viên**.
(Tổng = 1 + 3 + 6 = 10).

Bạn đã có hai công cụ quan trọng nhất:

1. Cách tính gạch cho một tầng mới.
2. Cách tính tổng số gạch đã tiêu tốn.

Bây giờ là mảnh ghép cuối cùng để giải quyết bài toán.

---

### BƯỚC 2: VÒNG LẶP TƯ DUY - CHUNK 3: ĐIỂM DỪNG (KHI NÀO DỪNG XÂY?)

**🧠 Logic (Explain):**
Chúng ta không biết trước tháp sẽ cao bao nhiêu. Vì vậy, chiến thuật ở đây là **"Thử và Sai" (Simulation)**.
Bạn sẽ xây từng tầng một, từ tầng 1, tầng 2, tầng 3...
Sau mỗi lần xây xong một tầng, bạn kiểm tra túi gạch của mình ().

Quy trình lặp (Loop):

1. Tính số gạch cần cho tầng tiếp theo.
2. Kiểm tra: Tổng số gạch đang có () có đủ để trả cho tầng này không?
* **Nếu đủ:** Xây tiếp (Tăng chiều cao lên 1, trừ bớt gạch đi).
* **Nếu thiếu:** Dừng lại ngay lập tức! Chiều cao hiện tại chính là đáp án.



👉 **Ẩn dụ:** Giống như bạn đi đổ xăng vậy. Bình xăng của bạn có  lít.

* Đi đoạn 1 tốn 1 lít -> Còn xăng -> Đi tiếp.
* Đi đoạn 2 tốn 3 lít -> Còn xăng -> Đi tiếp.
* ...
* Cho đến khi đoạn tiếp theo tốn nhiều xăng hơn số bạn còn lại trong bình -> Dừng xe.

**⚠️ Bẫy (Trap):**
Lỗi **"Quá trớn" (Off-by-one error)**.
Nhiều bạn viết vòng lặp `while` xong, kết quả in ra lại bị thừa 1 tầng (ví dụ đáp án là 4 thì lại in ra 5).
Lý do: Bạn cộng chiều cao lên *trước khi* kiểm tra xem có đủ gạch không. Hãy nhớ: **Chỉ khi chắc chắn đủ gạch mới được đếm tầng đó!**

**❓ Thử thách tư duy:**
Hãy làm "máy tính chạy bằng cơm" với trường hợp ****.

Hãy điền vào chỗ trống các bước sau:

* Tầng 1: Tốn 1 (Tổng tốn 1)  Đủ ()  Xây được tầng 1.
* Tầng 2: Tốn 3 (Tổng tốn )  Đủ ()  Xây được tầng 2.
* Tầng 3: Tốn 6 (Tổng tốn )  Đủ ()  Xây được tầng 3.
* Tầng 4: Tốn 10 (Tổng tốn )  Đủ ()  Xây được tầng 4.
* Tầng 5: Tốn 15 (Tổng tốn )  **???**

Vậy với , kết quả cuối cùng (chiều cao cao nhất) là bao nhiêu?
A. 4
B. 5
C. 35

*Cho tôi biết đáp án của bạn!*

Chính xác! Đáp án là **A. 4**.
(Vì đến tầng 5 cần tổng 35 viên, mà bạn chỉ có 25 viên nên không đủ xây tầng 5  dừng lại ở tầng 4).

Chúc mừng bạn! Bạn đã hoàn thành xuất sắc cả 3 mảnh ghép tư duy:

1. ✅ **Giá từng tầng:** Tăng dần theo cấp số cộng (1, 3, 6, 10...).
2. ✅ **Tổng chi phí:** Cộng dồn tất cả các tầng.
3. ✅ **Điều kiện dừng:** Khi chi phí vượt quá số gạch .

---

### BƯỚC 3: TỔNG KẾT & CHỐT GIẢI PHÁP (SOLUTION)

Bây giờ, hãy ghép tất cả lại thành một "bản thiết kế" (Algorithm) trước khi bạn bắt tay vào code.

**📝 Mã giả (Pseudocode) - Dạng văn xuôi:**

1. **Chuẩn bị:**
* Một biến đếm chiều cao tháp (`height` = 0).
* Một biến lưu số gạch cần cho tầng hiện tại (`current_level_gach` = 0).
* Biến `n` là số gạch bạn đang có (Input).


2. **Vòng lặp xây dựng (While):**
* Bắt đầu thử xây tầng tiếp theo (`height` + 1).
* Tính số gạch cần cho tầng này: `current_level_gach` mới = `current_level_gach` cũ + (`height` + 1).
* **Kiểm tra túi tiền:**
* Nếu số gạch còn lại (`n`)  số gạch cần cho tầng này:
* Trả tiền: `n` = `n` - `current_level_gach`.
* Xây xong: Tăng chiều cao lên 1 (`height`++).


* Nếu không đủ (`n` < `current_level_gach`):
* **DỪNG LẠI NGAY.**






3. **Kết quả:** In ra `height`.

---

**🚀 NEXT STEP:**
Bây giờ mọi thứ đã nằm trong đầu bạn. Bạn có muốn:

1. Tự viết code (C++/Python) dựa trên mã giả này để nộp thử?
2. Hay muốn tôi đưa ra một mẫu code khung (Skeleton code) để bạn điền vào chỗ trống?

Hãy chọn 1 hoặc 2 nhé!