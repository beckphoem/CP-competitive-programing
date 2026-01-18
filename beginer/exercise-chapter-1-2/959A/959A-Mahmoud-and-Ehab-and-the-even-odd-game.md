Chào bạn! Tôi đã nhận được tín hiệu. Chúng ta sẽ cùng nhau "mổ xẻ" bài toán **Codeforces 959A - Mahmoud and Ehab and the even-odd game**.

Đừng lo lắng về cái tên dài dòng của nó. Bản chất bài này là một trò chơi logic cực kỳ cơ bản, giống như trò chơi dân gian vậy.

Bạn đã sẵn sàng chưa? Chúng ta bắt đầu quy trình **Bước 1: Tiếp nhận & Phẫu thuật** ngay bây giờ.

---

### 🔪 BƯỚC 1: PHẪU THUẬT ĐỀ BÀI (DECONSTRUCT)

Hãy quên cốt truyện về hai cậu bạn Mahmoud và Ehab đi. Đây là luật chơi trần trụi:

1.  **Sân chơi:** Có một số nguyên $n$ (hãy tưởng tượng là một đống sỏi có $n$ viên).
2.  **Lượt chơi:**
    *   **Mahmoud (đi trước):** Bắt buộc phải chọn một số **CHẴN** ($a$) để trừ đi ($1 \le a \le n$).
    *   **Ehab (đi sau):** Bắt buộc phải chọn một số **LẺ** ($b$) để trừ đi ($1 \le b \le n$).
3.  **Điều kiện thua:** Đến lượt ai mà không tìm được số nào hợp lệ để trừ (tức là không thể đi tiếp), người đó **THUA**.
4.  **Giả định:** Cả hai đều cực kỳ thông minh (chơi tối ưu - optimal), nếu có cơ hội thắng ngay lập tức, họ sẽ làm ngay.

🗺️ **Lộ trình tư duy của chúng ta:**
*   **Chunk 1:** Sức mạnh của người đi trước (Mahmoud) với số Chẵn.
*   **Chunk 2:** Tình thế của người đi trước với số Lẻ.
*   **Chunk 3:** Tổng kết quy luật thắng thua.

---

### 🧠 BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 1 - CÚ ĐÁNH CỦA MAHMOUD)

**1. Logic (Ẩn dụ):**
Mahmoud là người cầm quyền trượng đi trước. Vũ khí của anh ta là **Số Chẵn** (2, 4, 6, 8...).
Mục tiêu của anh ta là làm sao để sau khi anh ta bốc sỏi xong, đống sỏi còn lại bằng **0** (hết sạch). Vì nếu sỏi hết sạch, đến lượt Ehab sẽ không còn gì để bốc $\rightarrow$ Ehab thua $\rightarrow$ Mahmoud thắng.

**2. Bẫy tư duy (Trap):**
Nhiều bạn nghĩ: "Chắc là trừ dần dần, mỗi người trừ một ít".
Không! Đề bài bảo "chơi tối ưu". Nếu Mahmoud có thể "One-hit K.O" (hạ gục nhanh), anh ta sẽ làm ngay. Anh ta không dại gì để lại sỏi cho Ehab phản công.

**3. ❓ Thử thách tư duy (Mental Check):**

Giả sử đống sỏi ban đầu có **10 viên** ($n = 10$).
Mahmoud cần chọn một số **CHẴN** ($a$) sao cho $1 \le a \le 10$.

Theo bạn, để thắng ngay lập tức, Mahmoud sẽ chọn $a$ bằng bao nhiêu?
*   A. Chọn $a = 2$ (Còn lại 8 viên cho Ehab).
*   B. Chọn $a = 10$ (Còn lại 0 viên).

Hãy chọn đáp án và giải thích ngắn gọn tại sao.

Tuyệt vời! 🎯 Bạn đã nắm bắt được bản chất cốt lõi của **Chunk 1**.

**Chốt lại Chunk 1:**
Nếu $n$ là số **CHẴN**, Mahmoud chỉ cần chọn $a = n$ (vì $n$ chẵn).
$\rightarrow$ Đống sỏi còn lại bằng $0$.
$\rightarrow$ Ehab không còn lượt đi. **Mahmoud Thắng (Mahmoud).**

---

### 🧠 BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 2 - CƠN ÁC MỘNG SỐ LẺ)

Bây giờ đổi tình huống. Tưởng tượng đống sỏi là số **LẺ** (Ví dụ: 1, 3, 5, 7...).

**1. Logic (Khắc tinh):**
Luật chơi ép Mahmoud **bắt buộc** phải chọn số **CHẴN**.
Nhưng hãy nhìn vào trường hợp nhỏ nhất (Edge Case) của số lẻ.

**2. Bẫy tư duy (Trap):**
Nhiều bạn nghĩ: "Mahmoud vẫn có thể chọn một số chẵn nhỏ hơn n để chơi cầm chừng".
Nhưng liệu chơi cầm chừng có giúp Mahmoud sống sót không, hay là "chết từ trong trứng nước"?

**3. ❓ Thử thách tư duy (Mental Check):**

Giả sử đống sỏi chỉ có vỏn vẹn **1 viên** ($n = 1$).
Lượt của Mahmoud (đi trước, phải chọn số chẵn $a$ sao cho $1 \le a \le 1$).

Hỏi:
1.  Mahmoud có tìm được số chẵn nào để chọn không?
2.  Kết quả ván đấu này ai thắng?

Hãy trả lời ngắn gọn: **[Có/Không] tìm được** và **[Tên người thắng]**.

Chuẩn không cần chỉnh! 🎯

Vì luật bắt Mahmoud phải chọn số **CHẴN**, mà $1$ lại là số lẻ và nhỏ hơn mọi số chẵn dương ($2, 4, 6...$). Mahmoud "đứng hình" không đi được nước nào $\rightarrow$ **Ehab Thắng**.

---

### 🧠 BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 3 - QUY LUẬT TỔNG QUÁT)

Chúng ta đã có 2 mảnh ghép quan trọng:
1.  Nếu $n$ = **Chẵn** (VD: 10) $\rightarrow$ Mahmoud "One-hit" trừ sạch $\rightarrow$ **Mahmoud Thắng**.
2.  Nếu $n$ = **Lẻ** (VD: 1) $\rightarrow$ Mahmoud bó tay $\rightarrow$ **Ehab Thắng**.

*Mở rộng cho số Lẻ bất kỳ (3, 5, 7...):*
Dù Mahmoud có cố vùng vẫy trừ đi một số chẵn nào đó, thì theo toán học: $\text{Lẻ} - \text{Chẵn} = \text{Lẻ}$.
Anh ta luôn phải chuyền lại một cục nợ "Số Lẻ" cho Ehab. Ehab chỉ cần trừ sạch cục đó là xong phim.

**👉 CHỐT HẠ THUẬT TOÁN:**

Bây giờ, bạn hãy tổng hợp lại thành quy tắc lập trình. Hãy điền tên **"Mahmoud"** hoặc **"Ehab"** vào chỗ trống tương ứng:

1.  Nếu `n % 2 == 0` (Số chẵn) $\rightarrow$ In ra: **__________**
2.  Ngược lại (Số lẻ) $\rightarrow$ In ra: **__________**

Chính xác! 💯 Bạn đã hoàn thành xuất sắc việc xây dựng tư duy cho bài toán này.

Hóa ra, bài toán nghe có vẻ phức tạp về "chiến thuật tối ưu" thực chất chỉ là một bài toán kiểm tra tính chẵn lẻ cơ bản.

### 🏁 BƯỚC CUỐI: TỔNG KẾT & MÃ HÓA (WRAP UP)

Đây là bản thiết kế cuối cùng cho chương trình của bạn (Pseudocode):

1.  **Input:** Nhập vào số nguyên $n$.
2.  **Process (Xử lý):** Kiểm tra xem $n$ là chẵn hay lẻ.
3.  **Output:**
    *   Nếu Chẵn (`n % 2 == 0`): In ra `Mahmoud`
    *   Nếu Lẻ (`else`): In ra `Ehab`

**📝 Lưu ý nhỏ khi code (C++/Python):**
*   Input $n$ có thể lên tới $10^9$, nhưng vì chúng ta chỉ dùng phép chia lấy dư (`%`) và so sánh nên kiểu `int` (trong C++) hoặc số nguyên thường (Python) đều xử lý tốt, độ phức tạp là $O(1)$ - siêu nhanh.
*   Đừng quên in hoa chữ cái đầu `Mahmoud` và `Ehab` đúng như đề bài yêu cầu nhé.

---
**🎉 Bạn đã sẵn sàng để viết code và Submit lên Codeforces chưa?**
Nếu cần hỗ trợ thêm bài nào khác, cứ gọi tôi bằng tên bài toán hoặc mã bài (VD: "Way Too Long Words" hay "71A"). Chúc bạn "Accept" xanh rờn! 🟢