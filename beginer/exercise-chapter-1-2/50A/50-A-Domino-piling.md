# Hướng Dẫn Tư Duy: Domino piling (50A)

Chào các bạn! Bài toán **Xếp Domino** nghe có vẻ giống một trò chơi xếp hình phức tạp, nhưng thực chất nó lại là một bài toán **Diện tích** siêu đơn giản.

Hãy cùng phân tích nhé!

---

## 1. Hình Dung Bài Toán

Bạn có một cái bảng hình chữ nhật kích thước $M \times N$ (ô vuông).
Bạn có rất nhiều quân Domino. Mỗi quân Domino có kích thước $2 \times 1$ (tức là nó che phủ được đúng **2 ô vuông**).

**Nhiệm vụ:** Xếp được càng nhiều quân Domino lên bảng càng tốt.
**Luật chơi:**
1.  Không xếp chồng lên nhau.
2.  Không xếp ra ngoài bảng.
3.  Có thể xoay ngang hoặc dọc tùy ý.

---

## 2. Tư Duy: Diện Tích Là Chân Ái

Thay vì đau đầu suy nghĩ nên xếp dọc hay xếp ngang ở góc nào, hãy nhìn bài toán dưới góc độ **Tổng Diện Tích**:

1.  **Diện tích cái bảng:** Bảng có $M$ hàng và $N$ cột.
    $\Rightarrow$ Tổng số ô vuông là: $S_{bảng} = M \times N$.

2.  **Diện tích một quân Domino:** Mỗi quân chiếm 2 ô.
    $\Rightarrow$ $S_{domino} = 2$.

3.  **Số quân tối đa:**
    Theo lý thuyết toán học, số quân tối đa bạn có thể đặt được chính là:
    $$ \text{Số quân} = \frac{\text{Tổng diện tích bảng}}{\text{Diện tích 1 quân}} $$

---

## 3. Có xếp kín được không?

Có bạn sẽ thắc mắc: *"Lỡ bảng hình thù kỳ quái làm mình không xếp kín được thì sao?"*

Rất may, với quân Domino $2 \times 1$, các nhà toán học đã chứng minh được rằng:
*   Chúng ta luôn có thể lấp đầy bảng nhiều nhất có thể mà không cần quan tâm đến cách xếp phức tạp.
*   Chỉ có **duy nhất 1 ô vuông** bị thừa ra nêú tổng diện tích bảng là số **LẺ**.
*   Nếu tổng diện tích bảng là số **CHẴN**, ta luôn xếp kín mít được 100%.

**Ví dụ:**
*   Bảng $2 \times 4 = 8$ ô (Chẵn). $\Rightarrow$ Xếp được $8 / 2 = 4$ quân. (Kín bảng).
*   Bảng $3 \times 3 = 9$ ô (Lẻ). $\Rightarrow$ Xếp được $9 / 2 = 4$ quân (dư 1, tức là 4.5 quân nhưng ta chỉ lấy phần nguyên là 4).

---

## 4. Gợi Ý Thuật Toán

Bài toán này trở về phép tính số học lớp 3:

1.  Tính tổng số ô vuông của bảng ($M \times N$).
2.  Chia đôi kết quả đó cho 2.
3.  Lấy phần nguyên (Bỏ phần thập phân).

**Mẹo nhỏ:** Trong lập trình C++, phép chia số nguyên (`/`) tự động bỏ phần thập phân.
Ví dụ: `9 / 2` máy tính sẽ tự hiểu là `4` (chứ không phải 4.5).
Do đó, bạn chỉ cần áp dụng đúng công thức diện tích là xong! Không cần dùng `if-else` để kiểm tra chẵn lẻ gì cả.

Chúc các bạn thành công!
