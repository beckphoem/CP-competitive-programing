Chào mừng bạn! Tôi đã nhận tín hiệu. Chúng ta sẽ cùng nhau "xử lý" bài toán **Codeforces 977A - Wrong Subtraction**.

Đây là một bài toán tuyệt vời để rèn luyện tư duy về **Điều kiện (Condition)** và **Vòng lặp (Loop)** mà không cần các công thức toán học phức tạp.

---

### 📝 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

**1. Tóm tắt đề bài (Ngôn ngữ con người):**
Hãy tưởng tượng bạn đang chơi một trò chơi biến đổi con số. Bạn có một số nguyên  và bạn *buộc phải* thực hiện một hành động biến đổi nó đúng  lần.
Hành động đó không cố định, mà nó phụ thuộc vào "cái đuôi" (chữ số cuối cùng) của con số hiện tại:

* Nếu cái đuôi khác 0: Giảm số đó đi 1 đơn vị.
* Nếu cái đuôi là 0: Cắt bỏ cái đuôi đó đi (tức là chia cho 10).

**2. Lộ trình tư duy (Thinking Roadmap):**
Để giải quyết bài này, chúng ta sẽ đi qua 2 mảnh ghép tư duy (Micro-chunks):

* **Chunk 1:** Cơ chế "Nhìn đuôi đoán bệnh" (Xác định xem làm gì với con số).
* **Chunk 2:** Cỗ máy lặp lại (Thực hiện đủ số lần yêu cầu).

Bạn đã sẵn sàng chưa? Chúng ta bắt đầu vào mảnh ghép đầu tiên nhé.

---

### 🧱 CHUNK 1: CƠ CHẾ "NHÌN ĐUÔI ĐOÁN BỆNH"

**🧠 Logic (Explain):**
Hãy tưởng tượng số  của bạn là một con thằn lằn. Chúng ta cần nhìn vào cái **đuôi** của nó (chữ số hàng đơn vị) để quyết định sẽ làm gì.

* **Tình huống 1:** Cái đuôi vẫn còn dài (Chữ số cuối ).
* *Hành động:* Chúng ta mài bớt đuôi đi một chút (Trừ đi 1).
* *Ví dụ:* 59  58.


* **Tình huống 2:** Cái đuôi đã trụi lủi (Chữ số cuối ).
* *Hành động:* Con thằn lằn tự rụng luôn khúc đuôi đó để thoát thân (Chia cho 10).
* *Ví dụ:* 50  5.



Trong lập trình, để lấy "cái đuôi" (chữ số cuối cùng) của một số nguyên, chúng ta thường dùng phép toán **chia lấy dư cho 10** (Modulus `%`).

**⚠️ Bẫy (Trap):**
Nhiều bạn vội vàng chia cho 10 ngay khi thấy số lớn, hoặc trừ 1 liên tục. Hãy nhớ: **Luôn phải nhìn cái đuôi trước khi hành động.**

**❓ Thử thách tư duy (Mental Check):**
Giả sử số hiện tại của bạn là . Bạn cần thực hiện **1 bước** biến đổi.
Theo luật chơi trên, kết quả mới sẽ là bao nhiêu?

A. 208
B. 20
C. 29

Hãy chọn đáp án và giải thích tại sao bạn chọn nó (dựa vào "cái đuôi" nhé).

Tuyệt vời! Bạn đã nắm chắc quy tắc cốt lõi rồi đấy.
Đúng là **A (208)**. Vì đuôi là  (khác ), nên chúng ta chỉ đơn giản là trừ đi .

Bây giờ, hãy ghép mảnh ghép đó vào bức tranh lớn hơn.

---

### 🧱 CHUNK 2: CỖ MÁY LẶP LẠI

**🧠 Logic (Explain):**
Đề bài không chỉ yêu cầu làm 1 lần, mà bắt chúng ta làm đúng  lần.
Hãy tưởng tượng  giống như số lượng **xăng** hoặc **năng lượng** bạn có.
Mỗi lần bạn thực hiện hành động "nhìn đuôi đoán bệnh" (ở Chunk 1), bạn tiêu tốn 1 đơn vị năng lượng.

Quy trình sẽ diễn ra như một vòng lặp:

1. Kiểm tra : Còn năng lượng không? (?)
2. Nếu còn: Thực hiện biến đổi  (theo quy tắc Chunk 1).
3. Giảm  đi 1 (vì đã làm xong 1 lần).
4. Quay lại bước 1.

Chúng ta sẽ dừng lại khi  (hết lượt). Lúc đó, hình dạng cuối cùng của con số  chính là đáp án.

**⚠️ Bẫy (Trap):**
Đừng lầm tưởng thứ tự. Chúng ta không trừ  ra khỏi .  là số lần lặp,  là đối tượng bị thay đổi. Hai biến này có vai trò hoàn toàn khác nhau.

**❓ Thử thách tư duy (Mental Check):**
Hãy chạy thử "bộ não" của bạn với dữ liệu này:

* Số ban đầu: 
* Số lần cần làm: 

Hãy lần lượt thực hiện từng bước và cho tôi biết kết quả cuối cùng sau **3 lần** biến đổi là bao nhiêu?

(Gợi ý: Đừng nhảy cóc, hãy viết ra từng bước biến đổi: 51  ...  ...  Kết quả)

Chính xác hoàn toàn! 🎯 Bạn đã tư duy đúng như cách máy tính vận hành rồi đấy.

**Phân tích lại bước đi của bạn:**

1. **51**: Đuôi là 1 (Lẻ loi)  Trừ 1  **50**. (Đã làm 1 lần)
2. **50**: Đuôi là 0 (Tròn trĩnh)  Chia 10  **5**. (Đã làm 2 lần)
3. **5**: Đuôi là 5 (Lẻ loi)  Trừ 1  **4**. (Đã làm 3 lần  Xong!)

Kết quả là 4. Bạn đã vượt qua tất cả các chướng ngại vật về logic!

---

### 📝 BƯỚC 3: TỔNG KẾT & MÃ GIẢ (BLUEPRINT)

Bây giờ, chúng ta hãy gom tất cả các mảnh ghép lại thành một "bản thiết kế" (Pseudocode) để chuẩn bị viết code. Chúng ta không cần quan tâm cú pháp C++ hay Python vội, chỉ quan tâm luồng đi thôi.

**📜 Bản thiết kế thuật toán:**

1. **Đầu vào (Input):** Nhận hai số nguyên  (số cần sửa) và  (số lần sửa).
2. **Vòng lặp (The Loop):** Chúng ta sẽ lặp lại hành động ** lần**.
* *Trong mỗi lần lặp:*
* Kiểm tra cái đuôi của  (bằng cách tính `n % 10`).
* **NẾU** đuôi bằng 0:
* Cập nhật `n = n / 10`.


* **NGƯỢC LẠI** (đuôi khác 0):
* Cập nhật `n = n - 1`.




3. **Kết thúc:** Sau khi lặp đủ  lần, in số  ra màn hình.

---

**👨‍💻 ĐẾN LƯỢT BẠN (YOUR TURN)**

Bạn đã có logic, đã có bản thiết kế. Bây giờ hãy thử chuyển nó thành code thật (C++, Python hoặc ngôn ngữ bạn chọn) và nộp thử (hoặc dán vào đây).

Nếu bạn cần gợi ý về cú pháp (ví dụ: làm sao để viết vòng lặp  lần), hãy nói cho tôi biết ngôn ngữ bạn đang dùng nhé!

**Bạn muốn tự viết code hay muốn xem một đoạn khung sườn (Template) trước?**