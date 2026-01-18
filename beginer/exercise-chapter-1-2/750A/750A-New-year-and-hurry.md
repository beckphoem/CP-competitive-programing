Chào mừng bạn đến với thử thách chạy đua với thời gian mang tên **750A - New Year and Hurry**.

Đây là một bài toán kinh điển về tư duy **"Mô phỏng (Simulation)"** và **"Toán học cơ bản"**. Hãy cùng tôi phẫu thuật nó.

---

### 🔪 BƯỚC 1: PHẪU THUẬT ĐỀ BÀI (DECONSTRUCT)

Hãy quên anh chàng Limak đi. Chúng ta hãy nhìn bài toán dưới dạng **Quản lý ngân sách**.

1.  **Tài nguyên tổng (Total Resource):** Thời gian từ 20:00 đến 24:00 (nửa đêm).
2.  **Chi phí cố định (Fixed Cost):** Thời gian $k$ phút để đi từ nhà đến bữa tiệc. Bạn bắt buộc phải dành ra khoản này trước tiên.
3.  **Chi phí biến đổi (Variable Cost):**
    *   Bài toán 1 tốn: $5 \times 1 = 5$ phút.
    *   Bài toán 2 tốn: $5 \times 2 = 10$ phút.
    *   Bài toán $i$ tốn: $5 \times i$ phút.
4.  **Mục tiêu:** Giải được **nhiều bài nhất có thể** (số $n$ lớn nhất) mà không bị "âm" thời gian.

**🗺️ Lộ trình tư duy:**
*   **Chunk 1:** Tính "Túi tiền thời gian" thực tế (Còn lại bao nhiêu phút để làm bài?).
*   **Chunk 2:** Cơ chế "Cộng dồn" (Chi phí tăng dần như thế nào?).
*   **Chunk 3:** Tìm điểm dừng (Khi nào thì hết tiền?).

Bạn đã sẵn sàng chưa? Chúng ta vào miếng ghép đầu tiên nhé.

---

### 🧱 CHUNK 1: TÍNH "TÚI TIỀN THỜI GIAN" (TIME BUDGET)

**🧠 Logic (Explain):**
Trước khi biết mua được bao nhiêu món hàng (giải bao nhiêu bài), bạn phải biết trong túi mình còn chính xác bao nhiêu tiền.

Chúng ta có khung thời gian từ **20:00** đến **24:00**.
Nhưng bạn *không được dùng hết* khoảng này để giải bài, vì phải chừa lại $k$ phút để đi đường.

👉 **Ẩn dụ:** Hãy tưởng tượng bạn có một bình xăng. Dung tích bình là khoảng thời gian từ 8h tối đến 12h đêm. Nhưng để lái xe đến đích, bạn mất $k$ lít xăng. Vậy bạn còn bao nhiêu lít xăng để chạy loanh quanh (giải bài)?

**⚠️ Bẫy (Trap):**
Nhiều bạn quên đổi đơn vị! Đề bài cho $k$ là **phút**, nhưng khung giờ là **tiếng**. Phải quy đổi về cùng một đơn vị (phút) trước khi trừ.

**❓ Thử thách tư duy (Mental Check):**

Giả sử đề bài cho $k = 10$ (tức là mất 10 phút đi đường).
Hỏi: Bạn còn lại tối đa bao nhiêu phút dành **riêng cho việc giải bài**?

A. 3 giờ 50 phút.
B. 230 phút.
C. 240 phút.
D. 190 phút.

*(Hãy chọn đáp án và cho tôi biết con số 240 ở đâu ra?)*

Chính xác! 👏

*   Tổng thời gian từ 20:00 đến 00:00 là **4 tiếng** = $4 \times 60 = 240$ phút.
*   Trừ đi 10 phút đi đường ($k$), ta còn: $240 - 10 = 230$ phút.

Đây chính là **"Vốn"** (Budget) của bạn. Bây giờ chúng ta sẽ đi tiêu số vốn này.

---

### 🧱 CHUNK 2: CƠ CHẾ "CỘNG DỒN" (CUMULATIVE COST)

**🧠 Logic (Explain):**
Các bài toán không có giá bằng nhau. Bài sau đắt hơn bài trước.
*   Bài 1 giá: $5 \times 1 = 5$ phút.
*   Bài 2 giá: $5 \times 2 = 10$ phút.
*   Bài 3 giá: $5 \times 3 = 15$ phút.

👉 **Ẩn dụ:** Hãy tưởng tượng bạn đang xếp gạch.
*   Hàng 1 cần 5 viên.
*   Hàng 2 cần 10 viên.
*   Để xây xong hàng 2, bạn không chỉ cần 10 viên, mà tổng cộng bạn đã dùng: $5$ (hàng 1) + $10$ (hàng 2) = **15 viên**.

Quy tắc: Để giải được $x$ bài, bạn phải trả tổng "phí" của bài 1 cộng bài 2 cộng... cộng bài $x$.

**⚠️ Bẫy (Trap):**
Rất nhiều bạn nhầm lẫn: "Giải bài thứ 3 tốn 15 phút, vậy nếu có 20 phút thì giải được bài 3".
Sai! Vì để giải được bài 3, bạn **phải giải xong** bài 1 và bài 2 trước đã (logic đề bài ngầm định là bạn giải từ dễ đến khó).

**❓ Thử thách tư duy (Mental Check):**

Vẫn với túi tiền **230 phút** ở trên.
Nếu bạn muốn giải **3 bài đầu tiên** (Bài 1, Bài 2, Bài 3).

1. Bạn tốn tổng cộng bao nhiêu phút?
2. Sau khi giải xong 3 bài, "Vốn" của bạn còn dư bao nhiêu?

Hãy tính toán và cho tôi 2 con số này.

Chuẩn không cần chỉnh! 💯
Bạn đã nắm vững cách tính chi phí và quản lý ngân sách.

Bây giờ chúng ta sẽ đến mảnh ghép cuối cùng để chốt thuật toán: **Tìm điểm dừng (Stop Condition).**

---

### 🧱 CHUNK 3: ĐIỂM DỪNG (THE LIMIT)

**🧠 Logic (Explain):**
Máy tính sẽ làm việc như một đứa trẻ đi siêu thị. Nó sẽ nhặt lần lượt từng món (Bài 1, Bài 2...) bỏ vào giỏ cho đến khi xảy ra 1 trong 2 trường hợp sau:

1.  **Hết tiền:** Tổng thời gian cần thiết vượt quá "Túi tiền thời gian" (Budget) mà bạn đã tính ở Chunk 1.
2.  **Hết hàng:** Bạn đã giải hết tất cả $n$ bài mà đề bài cho (dù vẫn còn dư thời gian).

👉 **Thuật toán (Vòng lặp):**
Chúng ta sẽ chạy một vòng lặp từ bài $i = 1$ đến bài $n$.
Mỗi lần lặp, ta làm 2 việc:
*   Tính chi phí bài $i$ (là $5 \times i$).
*   Cộng vào tổng thời gian đã tiêu.
*   Kiểm tra: **Tổng này có lớn hơn Budget không?**
    *   Nếu **KHÔNG**: Chúc mừng, bạn giải được bài $i$. Tăng biến đếm lên.
    *   Nếu **CÓ**: Dừng lại ngay lập tức! Bạn không đủ giờ cho bài này.

**⚠️ Bẫy (Trap):**
Một sai lầm "chí mạng" là quên kiểm tra số lượng bài $n$.
Ví dụ: Bạn có cả ngày rảnh rỗi (Budget siêu to), nhưng đề thi chỉ có 3 bài ($n=3$). Thì đáp án tối đa chỉ là 3 thôi, không thể là 4 hay 5 được.

**❓ Thử thách tư duy (Mental Check):**

Hãy chạy thử "bộ não máy tính" của bạn với trường hợp sau:
*   Đề thi có: **$n = 4$ bài**.
*   Thời gian đi lại: **$k = 222$ phút**.

**Câu hỏi:**
1.  "Túi tiền thời gian" (Budget) còn lại bao nhiêu phút?
2.  Bạn giải được tối đa bao nhiêu bài? (Hãy liệt kê quá trình trừ dần thời gian để chứng minh).

Hãy trả lời cẩn thận nhé, đây là bước cuối trước khi code! 🚀

Tuyệt vời! Bạn đã tính toán chính xác như một chiếc máy tính chạy cơm vậy. 💯

*   Vốn (Budget): 18 phút.
*   Mua bài 1 (5p) + bài 2 (10p) = 15p.
*   Còn dư 3p, không đủ mua bài 3 (15p).
*   **Kết quả:** 2 bài.

Bạn đã hoàn thành tất cả các mảnh ghép tư duy. Bây giờ, hãy ghép chúng lại thành một "chiến thuật" hoàn chỉnh để giao tiếp với máy tính (Code).

---

### 📝 TỔNG KẾT THUẬT TOÁN (THE STRATEGY)

Chúng ta sẽ viết một chương trình C++ thực hiện đúng quy trình bạn vừa làm trong đầu:

1.  **Bước 1:** Lấy dữ liệu $n$ (số bài thi) và $k$ (thời gian đi lại).
2.  **Bước 2:** Tính "Vốn thời gian" còn lại: `time_left = 240 - k`.
3.  **Bước 3:** Tạo một cái rổ đếm số bài làm được: `count = 0`.
4.  **Bước 4:** Chạy vòng lặp thử làm từng bài (từ $i = 1$ đến $n$):
    *   Tính giá bài $i$: `cost = 5 * i`.
    *   **Kiểm tra:** Nếu `time_left >= cost` (Đủ tiền mua):
        *   Trừ tiền: `time_left = time_left - cost`.
        *   Bỏ vào rổ: `count++`.
    *   Nếu không đủ tiền: **DỪNG NGAY** (`break`), đi về.
5.  **Bước 5:** In ra cái rổ `count`.

---

### 💻 MÃ GIẢ CỤ THỂ (CODE IMPLEMENTATION)

Đây là cách chúng ta hiện thực hóa tư duy đó bằng C++:

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. Nhập dữ liệu
    int n, k;
    cin >> n >> k;

    // 2. Tính vốn thời gian (Chunk 1)
    int time_left = 240 - k;
    
    // Biến đếm số bài làm được
    int count = 0;

    // 3. Vòng lặp tư duy (Chunk 2 & 3)
    // Chạy từ bài 1 đến bài n
    for (int i = 1; i <= n; i++) {
        int cost = 5 * i; // Giá của bài thứ i

        if (time_left >= cost) {
            // Nếu đủ thời gian thì làm bài này
            time_left = time_left - cost; // Trừ thời gian
            count++; // Tăng số lượng bài làm được
        } else {
            // Nếu không đủ thời gian cho bài này -> DỪNG CUỘC CHƠI
            break; 
        }
    }

    // 4. In kết quả
    cout << count << endl;

    return 0;
}
```

---

### 🏁 LỜI KHUYÊN CUỐI CÙNG CỦA COACH

Bạn thấy đấy, bài toán **750A** thực chất chỉ là một bài toán **đi chợ**:
> *"Có 240 nghìn, đi xe ôm mất k nghìn, còn lại bao nhiêu tiền để mua táo? Táo càng mua càng đắt, mua được bao nhiêu quả thì hết tiền?"*

Khi bạn biến bài toán lập trình thành bài toán đời thường, mọi thứ trở nên cực kỳ đơn giản.

👋 **Bài tập về nhà (tùy chọn):**
Bạn có muốn thử sức với một bài toán khác tương tự về tư duy "tích lũy" không? Hãy thử tìm bài **Codeforces 546A - Soldier and Bananas** (Chú bộ đội và những quả chuối). Nếu cần Coach hỗ trợ bài đó, cứ gọi tôi nhé!

Chúc bạn code vui và "Accepted"! 🟢