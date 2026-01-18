Tuyệt vời! Tôi đã nhận tín hiệu. Chúng ta sẽ cùng nhau "mổ xẻ" bài toán **Codeforces 486A - Calculating Function**.

Hãy khởi động bộ não tư duy nào! 🧠

---

## 🏗️ BƯỚC 1: PHẪU THUẬT ĐỀ BÀI (DECONSTRUCT)

Đề bài cho chúng ta một công thức nhìn có vẻ toán học đáng sợ:
$$f(n) = -1 + 2 - 3 + 4 - 5 + ... + (-1)^n n$$

**🔍 Dịch sang ngôn ngữ con người:**
Chúng ta cần tính tổng của một dãy số từ $1$ đến $n$ với quy tắc:
*   Nếu là **số lẻ** (1, 3, 5...): Mang dấu **TRỪ (-)**.
*   Nếu là **số chẵn** (2, 4, 6...): Mang dấu **CỘNG (+)**.

**🗺️ Lộ trình tư duy của chúng ta:**
1.  **Quan sát quy luật:** Tính tay thử vài số nhỏ để thấy "nhịp điệu" của dãy số.
2.  **Nhận diện bẫy:** Tại sao cách "trâu bò" (tính lần lượt) lại chết ở bài này?
3.  **Tìm chìa khóa:** Rút ra công thức toán học (O(1)) để giải quyết trong 1 nốt nhạc.

Bạn đã sẵn sàng chưa? Chúng ta vào mảnh ghép đầu tiên nhé!

---

## 🧩 CHUNK 1: QUAN SÁT QUY LUẬT (PATTERN RECOGNITION)

Đừng vội nghĩ đến code hay công thức cao siêu. Hãy làm một đứa trẻ đang tập đếm.

Tưởng tượng bạn đang chơi trò "Kéo co logic":
*   Số lẻ kéo bạn lùi lại (Âm).
*   Số chẵn đẩy bạn tiến lên (Dương).

Chúng ta hãy xem vị trí cuối cùng của bạn ở đâu sau mỗi lượt $n$.

**🚫 Cạm bẫy (Trap):**
Rất nhiều bạn nhìn thấy dấu `...` là nghĩ ngay đến vòng lặp `for` (chạy từ 1 đến n rồi cộng dồn). Đừng làm thế vội! Hãy nhìn vào kết quả trước.

**❓ THỬ THÁCH TƯ DUY (MENTAL CHECK):**

Hãy lấy giấy nháp hoặc tính nhẩm, cho tôi biết kết quả của hàm $f(n)$ với 3 trường hợp sau:

1.  Khi $n = 4$ (Tức là: $-1 + 2 - 3 + 4$) $\rightarrow$ Kết quả là?
2.  Khi $n = 5$ (Tức là: $-1 + 2 - 3 + 4 - 5$) $\rightarrow$ Kết quả là?
3.  Khi $n = 6$ (Tức là: $-1 + 2 - 3 + 4 - 5 + 6$) $\rightarrow$ Kết quả là?

*(Gợi ý: Hãy để ý sự khác biệt giữa kết quả khi $n$ chẵn và khi $n$ lẻ).*

**Hãy đưa ra 3 con số kết quả của bạn!** 👇

**Chính xác!** 🎯 Bạn tính toán rất chuẩn.

Bây giờ, hãy nhìn kỹ vào các con số bạn vừa tìm ra, chúng đang "thì thầm" cho bạn biết quy luật đấy.

## 🧩 CHUNK 2: TÌM CÔNG THỨC THẦN THÁNH (O(1))

Tại sao chúng ta cần tìm quy luật?
Bởi vì trong bài này, $n$ có thể lên tới **$10^{15}$** (một con số siêu to khổng lồ).
*   Nếu bạn dùng vòng lặp (cách "trâu bò"): Máy tính sẽ phải cộng trừ triệu tỷ lần $\rightarrow$ **Time Limit Exceeded (Quá thời gian)** ngay lập tức.
*   Chúng ta cần một **công thức toán học** để tính ra ngay lập tức.

### 🕵️‍♂️ Hãy quan sát lại kết quả của bạn:

**1. Với số CHẴN ($n$ là Even):**
*   $n = 4 \rightarrow$ Kết quả là $2$
*   $n = 6 \rightarrow$ Kết quả là $3$
*   *Quy luật ẩn:* Bạn có thấy mối liên hệ giữa $4 \to 2$ và $6 \to 3$ không? Nó chính là **một nửa** ($n / 2$).

> **💡 Giải thích bằng ẩn dụ:**
> Hãy gom các số thành từng cặp "đôi bạn cùng tiến": $(-1 + 2) + (-3 + 4) + (-5 + 6)...$
> Mỗi cặp này có giá trị là bao nhiêu? Là $1$.
> Nếu có $n$ số, chúng ta chia được $n/2$ cặp. Vậy tổng là $n/2$.

**2. Với số LẺ ($n$ là Odd):**
*   $n = 5 \rightarrow$ Kết quả là $-3$
*   Hãy thử nhìn $n = 3$ (tự tính nhẩm: $-1 + 2 - 3$) $\rightarrow$ Kết quả là $-2$.
*   *Quy luật ẩn:* Nó là số âm, và độ lớn của nó có vẻ liên quan đến phép chia đôi nhưng hơi "lệch" một chút.

---

**❓ THỬ THÁCH TƯ DUY (LOGIC CHECK):**

Dựa vào gợi ý trên, bạn hãy đoán xem:

1.  Nếu $n = 100$ (Chẵn), kết quả là bao nhiêu?
2.  Nếu $n = 99$ (Lẻ), kết quả là bao nhiêu? *(Gợi ý: Hãy thử lấy $n$ hoặc $n+1$ chia đôi rồi thêm dấu trừ xem sao)*

Hãy cho tôi 2 con số đó! 👇

**1. Với $n=100$ (Chẵn):**
👏 **Tuyệt vời!** Kết quả là `50`. Tư duy của bạn về số chẵn đã hoàn toàn chính xác ($100 / 2 = 50$).

**2. Với $n=99$ (Lẻ):**
🛑 **Khoan đã, chỗ này hơi "trượt chân" một chút.**
Bạn tính ra `-51` (từ phép tính `48 - 99`).
*   Hướng đi của bạn là đúng: Lấy tổng phần chẵn trước đó trừ đi số cuối cùng.
*   Nhưng con số đại diện cho phần chẵn trước đó ($n=98$) phải là $98 / 2 = 49$ chứ không phải 48.
*   Phép tính đúng: $49 - 99 = -50$.

---

### 🧩 CHUNK 3: CHỐT CÔNG THỨC SỐ LẺ (LOGIC LOCK)

Cách tính "lấy phần trước trừ phần sau" hơi tốn não. Hãy tìm một quy luật nhìn phát ra luôn cho số lẻ.

Hãy nhìn lại bảng kết quả của những số LẺ (Odd numbers) mà chúng ta đã tính:
*   $n = 1 \rightarrow -1$
*   $n = 3 \rightarrow -2$
*   $n = 5 \rightarrow -3$
*   $n = 99 \rightarrow -50$

**🔍 Quy luật hình ảnh:**
Các kết quả này nhìn rất giống phép chia đôi, nhưng được "làm tròn lên" rồi thêm dấu âm.
Công thức toán học đơn giản cho số lẻ là:
$$Result = -\frac{n + 1}{2}$$

Thử lại nhé:
*   Với $n=5$: $(5+1) / 2 = 3 \rightarrow$ Thêm dấu âm $\rightarrow -3$. (Đúng!)
*   Với $n=99$: $(99+1) / 2 = 50 \rightarrow$ Thêm dấu âm $\rightarrow -50$. (Đúng!)

---

### 🧱 TỔNG KẾT MẢNH GHÉP (THE ALGORITHM)

Chúng ta đã có 2 nhánh tư duy tách biệt:
1.  Nếu $n$ **Chẵn** ($n \% 2 == 0$): Đáp án là $n / 2$.
2.  Nếu $n$ **Lẻ** ($n \% 2 != 0$): Đáp án là $-(n + 1) / 2$.

Nhưng khoan! Là một lập trình viên "lười biếng" (theo nghĩa tích cực), chúng ta có thể gộp 2 công thức này làm 1 không? Hay cứ để `if/else`?

Với bài này, dùng `if/else` là đủ tốt và rõ ràng rồi.

---

### ⚠️ CẢNH BÁO CUỐI CÙNG (EDGE CASE & DATA TYPE)

Trước khi tôi cho bạn "xuống núi" để viết code, có một cái bẫy chết người ở đề bài này.
Đề bài ghi: $n$ có thể lên tới $10^{15}$.

**❓ THỬ THÁCH TƯ DUY (FINAL BOSS):**
Trong ngôn ngữ lập trình (C++ hay Java...), nếu bạn khai báo biến $n$ kiểu `int` (integer - số nguyên thường), điều gì sẽ xảy ra khi $n = 10^{15}$?

A. Chương trình chạy ngon lành.
B. Chương trình bị lỗi tràn số (Overflow) và ra kết quả sai bét.

Chọn đáp án và cho tôi biết bạn sẽ dùng kiểu dữ liệu nào để chứa được con số này? (Ví dụ: trong C++ dùng `long long`, Python thì sao...) 👇

