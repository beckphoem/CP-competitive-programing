Tuyệt vời! Tôi đã nhận diện nhiệm vụ. Tôi là **Coach Tư Duy Thuật Toán** của bạn.

Chúng ta sẽ cùng nhau "xử lý" bài **Codeforces 460A - Vasya and Socks**. Quên code đi, hãy bật chế độ tư duy logic lên nào.

---

# 🕵️ BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

Đầu tiên, hãy lột bỏ lớp vỏ bọc "Vasya" và "đôi tất" để nhìn thấy lõi toán học của bài toán này.

**📝 Tóm tắt đề bài (Ngôn ngữ con người):**
*   **Vốn khởi nghiệp:** Bạn có một lượng tài nguyên ban đầu là **$n$**.
*   **Luật tiêu dùng:** Mỗi ngày trôi qua, bạn buộc phải tiêu hao **1** đơn vị.
*   **Luật hồi phục (Bonus):** Cứ sau mỗi **$m$** ngày trôi qua, bạn được thưởng thêm **1** đơn vị vào kho.
*   **Mục tiêu:** Tìm xem sau bao nhiêu ngày thì bạn "phá sản" (tài nguyên về 0 và không thể tiêu dùng tiếp).

**🗺️ Lộ trình tư duy:**
1.  **Cơ chế dòng chảy:** Hiểu rõ cách tài nguyên giảm đi và tăng lên theo thời gian.
2.  **Mô phỏng (Simulation):** Chạy thử quy trình ngày qua ngày để tìm điểm kết thúc.
3.  **Bẫy vô tận:** Liệu có khi nào được tặng nhiều hơn số tiêu không? (Kiểm tra logic).

---

# 🧠 BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 1 - CƠ CHẾ DÒNG CHẢY)

Bắt đầu với mảnh ghép đầu tiên: **Sự thay đổi số lượng tất theo ngày.**

### 1. Logic (Ẩn dụ hóa)
Hãy tưởng tượng **$n$** là mức pin điện thoại.
*   Mỗi ngày pin tụt 1 vạch.
*   Cứ đến ngày thứ $m$, $2m$, $3m$... bạn cắm sạc dự phòng kích thêm được 1 vạch pin.

Vấn đề nằm ở chỗ: Cái "vạch pin" được sạc thêm đó, nó lại giúp điện thoại sống thêm được 1 ngày nữa. Và biết đâu trong cái ngày sống thêm đó, nó lại chạm mốc để được sạc tiếp?

### 2. Bẫy (Trap) ⚠️
Sai lầm phổ biến là dùng phép chia đơn thuần: Lấy Tổng số tất chia cho cái gì đó.
Cách này rất dễ sai vì bạn quên mất rằng: **Cái đôi tất được tặng thêm cũng sẽ được tính vào quy trình để nhận đôi tất tiếp theo.** Nó có tính "lãi suất kép" (dù lãi thấp).

### 3. Thử thách tư duy (Mental Check) ❓
Hãy chạy thử một bộ dữ liệu nhỏ trong đầu (Simulation) để hiểu cơ chế.

**Input:**
*   $n = 4$ (Có 4 đôi ban đầu)
*   $m = 2$ (Cứ 2 ngày thì được tặng 1 đôi)

**Diễn biến:**
*   **Ngày 1:** Dùng 1 đôi. Còn lại: 3. (Chưa đến ngày tặng).
*   **Ngày 2:** Dùng 1 đôi. Còn lại: 2.
    *   *Sự kiện:* Vì đã qua 2 ngày ($m=2$), bạn được +1 đôi.
    *   *Thực tế cuối ngày 2:* Bạn còn $2 + 1 = 3$ đôi.

👉 **Câu hỏi dành cho bạn:**
Dựa theo logic trên, hãy cho tôi biết:
1. Đến hết **Ngày 3**, trong tay bạn còn bao nhiêu đôi tất?
2. Đến hết **Ngày 4**, sự kiện "+1" có xảy ra không? Tại sao?

(Hãy trả lời để tôi biết bạn đã nắm được nhịp điệu của bài toán).

**Tuyệt vời! Bạn có trực giác toán học rất tốt.**

Phép tính `4 + 2 + 1 = 7` của bạn cho thấy bạn đã nắm được bản chất:
*   4 đôi gốc giúp bạn sống qua ngày 2 và 4 (được thưởng 2 đôi).
*   2 đôi thưởng đó giúp bạn sống qua ngày 6 (được thưởng thêm 1 đôi nữa).
*   1 đôi cuối cùng giúp sống nốt ngày 7.

---

# ⚙️ BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 2 - CHIẾN THUẬT MÔ PHỎNG)

Trực giác của bạn đúng, nhưng máy tính thì "ngốc" hơn. Nó không biết nhìn xa trông rộng để cộng dồn như bạn (`4+2+1`). Nó chỉ biết làm việc từng bước một (Step-by-step).

Chúng ta sẽ dạy máy tính cách **"Sống qua từng ngày"** (Simulation).

### 1. Logic (Cơ chế vận hành)
Hãy tưởng tượng chúng ta có 2 cái biến số:
1.  **Đồng hồ (Days):** Bắt đầu từ 0. Cứ mở mắt ra là tăng lên 1.
2.  **Kho tất (Socks):** Bắt đầu là $n$. Cứ mở mắt ra là giảm đi 1.

Quy trình mỗi sáng thức dậy:
*   `Kho tất` giảm 1.
*   `Đồng hồ` tăng 1.
*   **KIỂM TRA THƯỞNG:** Nhìn vào cái `Đồng hồ`. Nếu số ngày hiện tại chia hết cho $m$, bác đưa thư sẽ ném thêm 1 đôi vào `Kho tất`.

Vòng lặp này cứ chạy mãi cho đến khi `Kho tất` về 0.

### 2. Bẫy (Trap) ⚠️
Rất nhiều bạn mới học lập trình bị nhầm lẫn ở bước **KIỂM TRA THƯỞNG**.
*   Sai: Kiểm tra dựa trên số tất còn lại.
*   Đúng: Phải kiểm tra dựa trên **số ngày đã trôi qua** (Đồng hồ).

### 3. Thử thách tư duy (Mental Check) ❓

Để dạy máy tính biết "Ngày nào là ngày được thưởng", chúng ta cần một phép toán kiểm tra tính "chia hết".

Giả sử $m = 3$ (Cứ 3 ngày thưởng 1 lần).

Trong các ngày sau đây, ngày nào **sự kiện thưởng tất** sẽ xảy ra?
(Chọn các đáp án đúng)

A. Ngày thứ 2
B. Ngày thứ 3
C. Ngày thứ 5
D. Ngày thứ 6
E. Ngày thứ 9

👉 **Theo bạn, đặc điểm chung về mặt con số của những ngày được thưởng là gì?** (Gợi ý: Liên quan đến phép chia lấy dư).

**Chính xác!**

3, 6, 9... chính là các bội số của $m$.
Trong ngôn ngữ của máy tính, để kiểm tra điều này, chúng ta dùng phép **Chia lấy dư (Modulo - ký hiệu `%`)**.
Nếu `số_ngày % m == 0` (tức là chia hết, dư 0) $\rightarrow$ **Thưởng!**

---

# ⚔️ BƯỚC 2: VÒNG LẶP TƯ DUY (CHUNK 3 - THỨ TỰ SINH TỒN)

Đây là phần quan trọng nhất quyết định code đúng hay sai. Chúng ta cần sắp xếp thứ tự các hành động diễn ra trong một ngày thật chính xác.

### 1. Logic (Kịch bản trong ngày)
Hãy tưởng tượng trình tự diễn ra như sau:
1.  Sáng ngủ dậy, bạn rút 1 đôi tất ra đi (`n` giảm 1).
2.  Ngày trôi qua (`days` tăng 1).
3.  Chiều tối về, bạn nhìn lịch. Nếu hôm nay là ngày được thưởng (`days % m == 0`), bạn nhận thêm 1 đôi (`n` tăng 1).

**Vòng lặp tiếp tục miễn là trong kho còn tất (`n > 0`).**

### 2. Bẫy (Trap) - "Cú hồi sinh phút chót" ⚠️
Điều gì xảy ra nếu vào buổi sáng bạn lấy đi đôi tất **cuối cùng** (kho về 0), nhưng chiều tối hôm đó lại đúng là ngày được thưởng?

*   Nhiều bạn nghĩ: Kho về 0 là "Chết" (Game Over) luôn.
*   Thực tế: Nếu được thưởng vào chiều tối hôm đó, kho lại lên 1 $\rightarrow$ **Bạn vẫn sống sót sang ngày hôm sau!**

### 3. Thử thách tư duy (Mental Check) ❓

Hãy thử tình huống "ngàn cân treo sợi tóc" này:
*   **Input:** $n = 2$ (2 đôi), $m = 2$ (Cứ 2 ngày thưởng 1).

Hãy chạy theo kịch bản trên:
*   **Ngày 1:** Dùng 1 đôi $\rightarrow$ Còn 1. (Ngày 1 không thưởng).
*   **Ngày 2:** Dùng 1 đôi $\rightarrow$ Còn 0. (Kho sạch bách!).

👉 **Câu hỏi:**
Tại thời điểm cuối Ngày 2 này, chuyện gì xảy ra tiếp theo?
A. Hết tất rồi. Dừng lại. Kết quả là 2 ngày.
B. Vì là ngày 2 (chia hết cho 2), được thưởng 1 đôi. Kho từ 0 lên 1. Sống tiếp sang ngày 3.

Bạn chọn phương án nào?

**Tuyệt vời! Chính xác là phương án B.**

Đây chính là điểm "ăn tiền" của tư duy lập trình: **Thứ tự thực hiện lệnh (Order of Execution)**.
Máy tính sẽ không kiểm tra "Game Over" ngay khi tất về 0. Nó chỉ kiểm tra điều kiện lặp lại khi **chuẩn bị bắt đầu một vòng lặp mới**. Vì thế, cú "hồi máu" ở cuối ngày 2 đã cứu biến `n` thoát khỏi số 0, giúp vòng lặp tiếp tục.

---

# 🏁 BƯỚC 3: TỔNG KẾT & CHỐT THUẬT TOÁN (BLUEPRINT)

Chúng ta đã đi qua đủ các mảnh ghép:
1.  **Biến:** `n` (số tất), `days` (biến đếm ngày).
2.  **Vòng lặp:** Chạy miễn là còn tất (`while n > 0`).
3.  **Hành động:** Trừ tất, tăng ngày.
4.  **Điều kiện thưởng:** Nếu `days` chia hết cho `m` thì cộng tất.

Đây là **Bản thiết kế (Pseudocode)** cho giải pháp của bạn:

```text
BẮT ĐẦU:
   Nhập n, m
   Đặt biến đếm ngày (days) = 0

   TRONG KHI (n > 0):  <-- Chừng nào còn tất thì còn sống
       1. Giảm n đi 1      (Sáng ngủ dậy dùng 1 đôi)
       2. Tăng days lên 1  (Thời gian trôi qua)
       
       3. KIỂM TRA THƯỞNG:
          NẾU (days chia hết cho m):
              Tăng n lên 1 (Chiều tối được nhận quà)
   
   KẾT THÚC VÒNG LẶP:
   In ra số days
```

---

### 🚀 GIAI ĐOẠN CUỐI: TỪ TƯ DUY SANG CODE

Bây giờ, bạn đã có toàn bộ logic trong đầu.
Bạn có thể tự tin viết đoạn code này bằng ngôn ngữ bạn chọn (C++, Python...).

**Lưu ý nhỏ cuối cùng:**
*   Dùng vòng lặp `while`.
*   Phép chia hết là `%`.

**Bạn có muốn thử viết code ngay và dán vào đây để tôi review (kiểm tra) lần cuối không? Hay bạn muốn tôi đưa ra một "Công thức toán học siêu tốc" (cách giải O(1) không cần vòng lặp) cho bài này?**

Bạn có trực giác toán học rất sắc bén! 🎯

Ý tưởng **"cấp số nhân"** hay **"cộng dồn n/m"** của bạn (`n + n/m + n/m/m...`) là hoàn toàn đúng về mặt bản chất. Nó chính là cách tính tổng của chuỗi vô hạn.

Tuy nhiên, để biến nó thành công thức **O(1)** (tính một phát ra luôn, không cần cộng dồn nhiều lần), chúng ta cần thay đổi góc nhìn một chút.

Tôi sẽ giúp bạn "bẻ khóa" công thức này bằng tư duy **"Chi phí thực" (Net Cost)** thay vì cộng dồn.

---

# 🧠 MẢNH GHÉP TƯ DUY: CHI PHÍ THỰC CỦA MỘT NGÀY THƯỞNG

### 1. Phân tích "Lỗ - Lãi"
Hãy nhìn vào chu kỳ **$m$ ngày**:
*   Để sống qua $m$ ngày, bạn phải bỏ ra **$m$** đôi tất.
*   Nhưng ngay sau đó, bạn được hoàn lại **1** đôi.

👉 **Kết luận:** Thực chất, để "mua" được chu kỳ $m$ ngày đó (và tiếp tục game), kho tất của bạn chỉ bị hụt đi:
$$m - 1 \quad (\text{đôi})$$

Điều này có nghĩa là: **Cứ mỗi lần bạn chấp nhận mất đi $(m-1)$ đôi tất từ vốn gốc, bạn sẽ có thêm 1 đôi tất thưởng.**

### 2. Công thức sơ khai
Vậy, tổng số tất **được thưởng** (Bonus) sẽ bằng:
$$ \text{Số tất thưởng} = \frac{\text{Tổng vốn gốc}}{\text{Chi phí thực cho 1 lần thưởng}} = \frac{n}{m - 1} $$

Tổng số ngày sống được = **Vốn gốc ($n$) + Số tất thưởng**.

### 3. Cái bẫy của "Đôi tất cuối cùng" (Edge Case) ⚠️
Công thức $\frac{n}{m - 1}$ rất đẹp, nhưng nó bị sai ở tình huống biên.
Tại sao? Vì bạn **không thể đánh đổi đôi tất cuối cùng** theo cách này được. Để nhận thưởng, bạn phải *đi hết* chu kỳ.

Nếu bạn còn đúng 1 đôi, bạn đi nốt ngày hôm đó rồi hết. Bạn không thể nói: "Cho tôi ứng trước phần thưởng".

👉 **Mẹo toán học (Trick):**
Chúng ta sẽ "cất đi" 1 đôi tất (đôi cuối cùng) để đảm bảo an toàn, chỉ mang $(n-1)$ đôi ra để tính xem đổi được bao nhiêu phần thưởng.

Công thức chính xác là:
$$ \text{Số tất thưởng} = \text{phần nguyên của } \left( \frac{n - 1}{m - 1} \right) $$

---

# 🚀 CÔNG THỨC THẦN THÁNH O(1)

Tổng số ngày = Số tất gốc + Số tất thưởng

$$ \text{Kết quả} = n + \left\lfloor \frac{n - 1}{m - 1} \right\rfloor $$

*(Ký hiệu $\lfloor \dots \rfloor$ là phép chia lấy phần nguyên trong lập trình)*

### 🧪 Kiểm chứng (Mental Check)

Hãy thử lại với ví dụ $n = 4, m = 2$ mà chúng ta đã tính ra 7 ngày ở trên.

*   Áp dụng công thức:
    $$ 4 + \frac{4 - 1}{2 - 1} $$
    $$ = 4 + \frac{3}{1} $$
    $$ = 4 + 3 = 7 $$
    👉 **Chính xác!**

Thử một ví dụ khác: $n = 6, m = 3$.
*   Chạy tay (Simulation):
    *   6 đôi gốc.
    *   Ngày 3: còn 3, được +1 $\rightarrow$ kho 4.
    *   Ngày 6: còn 1, được +1 $\rightarrow$ kho 2.
    *   Ngày 7, 8: hết.
    *   Tổng = 8 ngày.
*   Áp dụng công thức:
    $$ 6 + \frac{6 - 1}{3 - 1} = 6 + \frac{5}{2} $$
    *   Trong lập trình số nguyên: $5 / 2 = 2$ (lấy phần nguyên).
    *   Kết quả: $6 + 2 = 8$.
    👉 **Chính xác!**

---

# 💻 CODE O(1) (C++ & Python)

Dưới đây là cách viết ngắn gọn nhất, không dùng vòng lặp `while`.

**C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Công thức O(1)
    cout << n + (n - 1) / (m - 1) << endl;
    return 0;
}
```

**Python:**
```python
n, m = map(int, input().split())
# Phép chia // trong Python lấy phần nguyên
print(n + (n - 1) // (m - 1))
```

### 💡 Bài học rút ra (Takeaway)
Khi gặp bài toán dạng **"Cứ dùng A thì được hồi lại B"**, hãy nhớ đến tư duy **"Chi phí thực = A - B"**. Nó sẽ giúp bạn biến một bài toán mô phỏng (Simulation) thành một bài toán chia đơn giản (Math).

Bạn đã nắm được logic của công thức này chưa? Có chỗ nào cảm thấy "lấn cấn" không?

Bạn có trực giác toán học rất sắc bén! 🎯

Ý tưởng **"cấp số nhân"** hay **"cộng dồn n/m"** của bạn (`n + n/m + n/m/m...`) là hoàn toàn đúng về mặt bản chất. Nó chính là cách tính tổng của chuỗi vô hạn.

Tuy nhiên, để biến nó thành công thức **O(1)** (tính một phát ra luôn, không cần cộng dồn nhiều lần), chúng ta cần thay đổi góc nhìn một chút.

Tôi sẽ giúp bạn "bẻ khóa" công thức này bằng tư duy **"Chi phí thực" (Net Cost)** thay vì cộng dồn.

---

# 🧠 MẢNH GHÉP TƯ DUY: CHI PHÍ THỰC CỦA MỘT NGÀY THƯỞNG

### 1. Phân tích "Lỗ - Lãi"
Hãy nhìn vào chu kỳ **$m$ ngày**:
*   Để sống qua $m$ ngày, bạn phải bỏ ra **$m$** đôi tất.
*   Nhưng ngay sau đó, bạn được hoàn lại **1** đôi.

👉 **Kết luận:** Thực chất, để "mua" được chu kỳ $m$ ngày đó (và tiếp tục game), kho tất của bạn chỉ bị hụt đi:
$$m - 1 \quad (\text{đôi})$$

Điều này có nghĩa là: **Cứ mỗi lần bạn chấp nhận mất đi $(m-1)$ đôi tất từ vốn gốc, bạn sẽ có thêm 1 đôi tất thưởng.**

### 2. Công thức sơ khai
Vậy, tổng số tất **được thưởng** (Bonus) sẽ bằng:
$$ \text{Số tất thưởng} = \frac{\text{Tổng vốn gốc}}{\text{Chi phí thực cho 1 lần thưởng}} = \frac{n}{m - 1} $$

Tổng số ngày sống được = **Vốn gốc ($n$) + Số tất thưởng**.

### 3. Cái bẫy của "Đôi tất cuối cùng" (Edge Case) ⚠️
Công thức $\frac{n}{m - 1}$ rất đẹp, nhưng nó bị sai ở tình huống biên.
Tại sao? Vì bạn **không thể đánh đổi đôi tất cuối cùng** theo cách này được. Để nhận thưởng, bạn phải *đi hết* chu kỳ.

Nếu bạn còn đúng 1 đôi, bạn đi nốt ngày hôm đó rồi hết. Bạn không thể nói: "Cho tôi ứng trước phần thưởng".

👉 **Mẹo toán học (Trick):**
Chúng ta sẽ "cất đi" 1 đôi tất (đôi cuối cùng) để đảm bảo an toàn, chỉ mang $(n-1)$ đôi ra để tính xem đổi được bao nhiêu phần thưởng.

Công thức chính xác là:
$$ \text{Số tất thưởng} = \text{phần nguyên của } \left( \frac{n - 1}{m - 1} \right) $$

---

# 🚀 CÔNG THỨC THẦN THÁNH O(1)

Tổng số ngày = Số tất gốc + Số tất thưởng

$$ \text{Kết quả} = n + \left\lfloor \frac{n - 1}{m - 1} \right\rfloor $$

*(Ký hiệu $\lfloor \dots \rfloor$ là phép chia lấy phần nguyên trong lập trình)*

### 🧪 Kiểm chứng (Mental Check)

Hãy thử lại với ví dụ $n = 4, m = 2$ mà chúng ta đã tính ra 7 ngày ở trên.

*   Áp dụng công thức:
    $$ 4 + \frac{4 - 1}{2 - 1} $$
    $$ = 4 + \frac{3}{1} $$
    $$ = 4 + 3 = 7 $$
    👉 **Chính xác!**

Thử một ví dụ khác: $n = 6, m = 3$.
*   Chạy tay (Simulation):
    *   6 đôi gốc.
    *   Ngày 3: còn 3, được +1 $\rightarrow$ kho 4.
    *   Ngày 6: còn 1, được +1 $\rightarrow$ kho 2.
    *   Ngày 7, 8: hết.
    *   Tổng = 8 ngày.
*   Áp dụng công thức:
    $$ 6 + \frac{6 - 1}{3 - 1} = 6 + \frac{5}{2} $$
    *   Trong lập trình số nguyên: $5 / 2 = 2$ (lấy phần nguyên).
    *   Kết quả: $6 + 2 = 8$.
    👉 **Chính xác!**

---

# 💻 CODE O(1) (C++ & Python)

Dưới đây là cách viết ngắn gọn nhất, không dùng vòng lặp `while`.

**C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Công thức O(1)
    cout << n + (n - 1) / (m - 1) << endl;
    return 0;
}
```

**Python:**
```python
n, m = map(int, input().split())
# Phép chia // trong Python lấy phần nguyên
print(n + (n - 1) // (m - 1))
```

### 💡 Bài học rút ra (Takeaway)
Khi gặp bài toán dạng **"Cứ dùng A thì được hồi lại B"**, hãy nhớ đến tư duy **"Chi phí thực = A - B"**. Nó sẽ giúp bạn biến một bài toán mô phỏng (Simulation) thành một bài toán chia đơn giản (Math).

Bạn đã nắm được logic của công thức này chưa? Có chỗ nào cảm thấy "lấn cấn" không?