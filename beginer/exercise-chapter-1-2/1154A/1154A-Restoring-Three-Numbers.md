Chào mừng bạn! Tôi đã nhận tín hiệu. Hôm nay chúng ta sẽ cùng "phẫu thuật" bài **Codeforces 1154A - Restoring Three Numbers**.

Đây là một bài toán rất tuyệt để luyện tư duy quan sát, không cần thuật toán cao siêu, chỉ cần **Logic Toán học cơ bản**.

---

### 🟢 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

**1. Bản chất đề bài (Ngôn ngữ con người):**
Người ta có 3 số bí mật là $a, b, c$ (tất cả đều lớn hơn 0).
Người ta đã tính toán và tạo ra 4 con số kết quả từ 3 số bí mật đó:
*   $a + b$
*   $a + c$
*   $b + c$
*   $a + b + c$

Sau đó, người ta xáo trộn 4 con số kết quả này và đưa cho bạn (Input).
**Nhiệm vụ:** Từ 4 con số lộn xộn đó, hãy tìm lại 3 số $a, b, c$ ban đầu.

**2. Lộ trình tư duy (Roadmap):**
Chúng ta sẽ giải quyết bài này qua 2 mảnh ghép (Chunks):
*   **Chunk 1:** Truy tìm "Trùm cuối" (Số lớn nhất đại diện cho cái gì?).
*   **Chunk 2:** Công thức ngược (Tìm lại từng thành phần).

Bạn đã sẵn sàng khởi động chưa? Chúng ta vào mảnh ghép đầu tiên nhé!

---

### 🟢 BƯỚC 2: VÒNG LẶP TƯ DUY - CHUNK 1: TRUY TÌM "TRÙM CUỐI"

#### 1. Logic (Ẩn dụ hóa)
Hãy tưởng tượng $a, b, c$ là cân nặng của 3 quả tạ: Tạ A, Tạ B và Tạ C.
Người ta cân các cặp (A+B, A+C, B+C) và cân cả 3 quả cùng lúc (A+B+C).

Trong 4 lần cân đó, vì trọng lượng các quả tạ đều là số dương (> 0), nên chắc chắn lần cân **tất cả 3 quả** sẽ cho ra con số nặng nhất.

👉 **Quy luật:** Trong 4 số đầu vào (Input), số có giá trị **LỚN NHẤT (MAX)** chính là tổng $S = a + b + c$.

#### 2. Bẫy (Trap) ⚠️
Rất nhiều bạn mới học thường nghĩ: "Số đầu tiên trong input là $a+b$, số thứ hai là $a+c$...".
**Sai!** Đề bài nói 4 số này bị **xáo trộn ngẫu nhiên**. Số lớn nhất có thể nằm ở bất cứ vị trí nào (đầu, cuối, hoặc giữa). Bạn phải tìm ra nó trước.

#### 3. Thử thách tư duy (Mental Check) ❓
Giả sử máy tính đưa cho bạn 4 con số sau (Input):
`3  6  5  4`

**Câu hỏi:**
1. Đâu là số đại diện cho $a + b + c$ (Tổng cả 3 số)?
2. Ba số còn lại (`3, 5, 4`) đại diện cho những giá trị nào (về mặt công thức)?

Hãy suy nghĩ và trả lời tôi nhé! 🧠

Tuyệt vời! Bạn đã bắt được "Trùm cuối" chính xác. 🎯
Số lớn nhất luôn là tổng của cả 3, và những số còn lại là tổng của từng cặp đôi.

Bây giờ chúng ta sang mảnh ghép quyết định để giải bài toán này.

---

### 🟢 BƯỚC 2: VÒNG LẶP TƯ DUY - CHUNK 2: THÁO GỠ (TÌM LẠI A, B, C)

#### 1. Logic (Phép toán trừ) ➖
Chúng ta đã có:
*   **Tổng lớn (`Max`):** $a + b + c$
*   **Các số nhỏ (`x1, x2, x3`):** Ví dụ một số là $a + b$

Làm thế nào để tìm ra số $c$ bị thiếu?
Rất đơn giản, hãy làm phép trừ:
$$ (a + b + c) - (a + b) = c $$

👉 **Nôm na là:** Lấy cái **Tổng lớn nhất** trừ đi **một số nhỏ bất kỳ**, phần dư ra chính là con số bí mật thứ 3 chưa có mặt trong cái tổng nhỏ đó.

#### 2. Bẫy (Trap) ⚠️
Đừng quan tâm thứ tự số nào là $a$, số nào là $b$, số nào là $c$. Đề bài chỉ yêu cầu in ra 3 số đó, in theo thứ tự nào cũng được (Codeforces chấp nhận hết).
Chỉ cần nhớ: **Lấy MAX trừ đi 3 số còn lại lần lượt.**

#### 3. Thử thách tư duy (Mental Check) ❓
Quay lại ví dụ lúc nãy:
*   Input: `3  6  5  4`
*   Bạn đã xác định **Max = 6**.
*   Ba số còn lại là: `3`, `5`, `4`.

**Nhiệm vụ:**
Hãy áp dụng "Công thức trừ" ở trên để tìm ra 3 con số $a, b, c$ ban đầu.
Kết quả là 3 số nào?

*(Gợi ý: Lấy 6 trừ đi từng số còn lại)*

Chính xác hoàn toàn! 👏

Bạn đã tìm ra 3 số bí mật là **3, 1, 2**.
Kiểm chứng lại nhé:
*   Tổng $3 + 1 + 2 = 6$ (Chính là số Max).
*   Các cặp tổng: $3+1=4$, $1+2=3$, $3+2=5$.
*   Input ban đầu: `3 6 5 4` $\rightarrow$ Khớp hoàn toàn!

---

### 🟢 BƯỚC 3: TỔNG KẾT CHIẾN THUẬT (WRAP UP)

Chúng ta đã đi xong phần tư duy. Bây giờ hãy chuyển hóa nó thành **chiến thuật cho máy tính**.

Vì 4 số đầu vào bị xáo trộn, cách đơn giản nhất để máy tính biết đâu là "Trùm cuối" (Max) mà không cần viết quá nhiều lệnh `if/else` so sánh là gì?

👉 **Chiến thuật: "Xếp hàng" (Sorting)**

Hãy tưởng tượng bạn có 4 thẻ bài số trên tay.
1.  **Bước 1:** Nhận 4 thẻ bài (Input vào một Mảng/List).
2.  **Bước 2:** Sắp xếp 4 thẻ bài theo thứ tự tăng dần (Số bé đứng trước, số lớn đứng sau).
    *   Ví dụ: `[3, 6, 5, 4]` $\rightarrow$ Sắp xếp thành `[3, 4, 5, 6]`.
3.  **Bước 3:** Khi đã sắp xếp xong, số nằm ở vị trí cuối cùng (index 3) chắc chắn là **Max** ($a+b+c$). Ba số đầu tiên (index 0, 1, 2) là các cặp tổng con.
4.  **Bước 4:** In ra kết quả:
    *   `(Max - Số thứ 0)`
    *   `(Max - Số thứ 1)`
    *   `(Max - Số thứ 2)`

---

### 🏁 BÀI TẬP VỀ ĐÍCH (FINAL CHALLENGE)

Trước khi bạn bắt tay vào code, tôi muốn bạn viết **Mã giả (Pseudocode)** hoặc mô tả bằng lời 3 dòng code quan trọng nhất để giải bài này.

*Gợi ý: Dòng 1 làm gì với mảng? Dòng 2 in cái gì?*

Mời bạn thể hiện! 🎤