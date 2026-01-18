# Hướng Dẫn Tư Duy: Elephant (617A)

Chào các bạn! Bài toán **Chú Voi Con** này là một ví dụ kinh điển cho chiến thuật "Tham lam" (Greedy) - tức là luôn chọn cái tốt nhất ở thời điểm hiện tại.

Hãy xem chú Voi thông minh của chúng ta tính toán thế nào nhé!

---

## 1. Tình Huống

*   Voi đang ở vị trí **0**.
*   Nhà Voi ở vị trí **$x$** (ví dụ $x = 12$).
*   Đôi chân của Voi có thể bước các bước dài: **1, 2, 3, 4, hoặc 5** mét.
*   **Mục tiêu:** Về nhà với **số bước ít nhất**.

---

## 2. Chiến Thuật: Bước Dài Nhất Có Thể

Nếu bạn muốn về nhà nhanh nhất, bạn có chọn đi nhích từng bước 1 mét không? Chắc chắn là không rồi! Bạn sẽ muốn nhảy những bước **xa nhất có thể**.

*   Bước xa nhất Voi có thể đi là **5 mét**.
*   Vậy chiến thuật tối ưu là: **Cứ bước 5 mét liên tục cho đến khi gần đến nhà.**

**Ví dụ: Nhà ở vị trí 12.**
*   Bước 1: Đi 5m (Đến vị trí 5). Còn cách nhà 7m.
*   Bước 2: Đi 5m nữa (Đến vị trí 10). Còn cách nhà 2m.
*   Bước 3: Còn 2m cuối cùng. Vì Voi có thể bước 1, 2, 3, 4, 5 nên bước 2m **nằm trong khả năng**. Voi bước một bước 2m nữa là về đến nhà.
    $\Rightarrow$ Tổng cộng: **3 bước**.

---

## 3. Phân Tích Tổng Quát

Bài toán này thực chất là tìm xem số $x$ chứa được bao nhiêu số 5.

Có 2 trường hợp xảy ra:

### Trường hợp 1: Chia hết cho 5
*   Ví dụ: $x = 10$.
*   $10 = 5 + 5$.
*   $\Rightarrow$ Voi đi đúng **$10 / 5 = 2$** bước là vừa đẹp.

### Trường hợp 2: Không chia hết cho 5 (Có dư)
*   Ví dụ: $x = 12$.
*   $12 = 5 + 5 + (dư \ 2)$.
*   Ta đi được $12 / 5 = 2$ bước dài.
*   Phần dư còn lại (2 mét) bắt buộc phải đi thêm **1 bước nữa**. (Dù dư 1, 2, 3 hay 4 thì cũng chỉ cần 1 bước là tới, vì Voi bước được tối đa 5).
*   $\Rightarrow$ Tổng số bước = **$(12 / 5) + 1$** = 3 bước.

---

## 4. Công Thức Tư Duy

Số bước đi chính là kết quả của phép chia làm tròn lên (Ceiling):
$$ \lceil \frac{x}{5} \rceil $$

Để cài đặt logic này cho máy tính, bạn có thể dùng cấu trúc rẽ nhánh `if-else`:
1.  Nếu $x$ chia hết cho 5: Kết quả là $x / 5$.
2.  Nếu $x$ không chia hết cho 5: Kết quả là $(x / 5) + 1$.

Rất đơn giản và tự nhiên đúng không nào? Hãy thử sức viết code nhé!
