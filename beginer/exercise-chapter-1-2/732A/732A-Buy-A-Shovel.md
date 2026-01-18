Chào mừng bạn! Tôi đã nhận tín hiệu. Tôi là **Coach Tư Duy Thuật Toán** của bạn đây.

Hôm nay chúng ta sẽ cùng "mổ xẻ" bài toán **Codeforces 732A - Buy a Shovel (Mua xẻng)**. Đừng lo về code vội, hãy cất bàn phím đi và dùng "bộ não" trước đã.

---

## 🏗 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

Đề bài kể về anh chàng Polycarp đi mua xẻng, nhưng chúng ta hãy gạt bỏ câu chuyện đó sang một bên. Đây là cốt lõi logic của vấn đề:

**1. Dữ liệu đầu vào (Input):**
*   `k`: Giá tiền của **một** chiếc xẻng.
*   `r`: Mệnh giá của một đồng xu lẻ duy nhất mà bạn có (trong túi bạn có vô hạn tờ tiền mệnh giá 10, nhưng chỉ có đúng **một** đồng xu mệnh giá `r`).

**2. Mục tiêu (Goal):**
*   Tìm số lượng xẻng **ít nhất** (gọi là `x`) mà bạn cần mua.
*   **Điều kiện:** Bạn phải trả tiền **vừa đủ khít** (không thối lại tiền thừa).

**3. Công cụ thanh toán:**
*   Bạn chỉ có thể trả bằng các tờ tiền **10 đồng** (số lượng vô hạn).
*   Và (tùy chọn) dùng thêm đúng **một đồng xu `r`** nếu muốn.

---

### 🗺 Lộ trình tư duy (Roadmap)

Chúng ta sẽ giải quyết bài toán này qua 3 mảnh ghép (Chunks):
1.  **Chunk 1:** Phân tích "Cơ chế ví tiền" (Điều kiện chia hết).
2.  **Chunk 2:** Truy tìm "Chữ số tận cùng" (Last Digit Logic).
3.  **Chunk 3:** Chiến thuật thử sai (Simulation).

---

Bạn đã sẵn sàng bước vào **Chunk 1: Phân tích cơ chế ví tiền** chưa? Hãy gõ **"Sẵn sàng"** hoặc thả một icon để bắt đầu!

Tuyệt vời! Chúng ta bắt đầu nhé.

---

## 🧱 CHUNK 1: CƠ CHẾ VÍ TIỀN (ĐIỀU KIỆN THANH TOÁN)

Hãy tưởng tượng bạn đang đứng trước quầy thu ngân.
Tổng số tiền bạn phải trả là:
$$S = k \times x$$
*(Trong đó: $k$ là giá 1 cái xẻng, $x$ là số xẻng bạn mua)*.

Trong túi bạn có:
1.  Rất nhiều tờ **10 đồng**.
2.  Đúng **1 đồng xu lẻ** mệnh giá $r$.

Để bác bán hàng không phải thối lại tiền (trả vừa đủ), tổng số tiền $S$ phải thỏa mãn 1 trong 2 trường hợp sau:

*   **Trường hợp 1:** Bạn chỉ dùng toàn tờ 10 đồng.
    *   👉 Nghĩa là $S$ phải chia hết cho 10 (Tận cùng là số **0**).
*   **Trường hợp 2:** Bạn dùng các tờ 10 đồng và kèm thêm đồng xu $r$ đó.
    *   👉 Nghĩa là ($S - r$) phải chia hết cho 10. Hay nói đơn giản hơn: $S$ có chữ số tận cùng đúng bằng **$r$**.

⚡ **TÓM LẠI:** Chúng ta chỉ quan tâm đến **Chữ số tận cùng** (Last Digit) của Tổng tiền $S$. Nó bắt buộc phải là **0** hoặc **$r$**.

---

### ⚠️ Cạm bẫy (Trap)
Nhiều bạn nghĩ rằng bắt buộc phải dùng đồng xu $r$.
**Sai!** Bạn có thể cất đồng xu đó đi nếu Tổng tiền $S$ đã tròn chục (tận cùng là 0).

---

### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Giả sử giá xẻng **$k = 12$** và đồng xu lẻ **$r = 8$**.

Tôi sẽ mua số lượng xẻng ($x$) khác nhau. Bạn hãy tính Tổng tiền ($S$) và xem có trả tiền được không nhé?

1.  Mua **$x = 1$** cái $\rightarrow S = 12$. (Tận cùng là 2). **Có trả được không?**
2.  Mua **$x = 4$** cái $\rightarrow S = 48$. (Tận cùng là 8). **Có trả được không?**
3.  Mua **$x = 5$** cái $\rightarrow S = 60$. (Tận cùng là 0). **Có trả được không?**

Hãy trả lời: **[Có/Không]** cho từng trường hợp và giải thích ngắn gọn tại sao.

Chính xác hoàn toàn! 🎉

*   **x=4, S=48:** Tận cùng là 8 (trùng với $r=8$) $\rightarrow$ **OK** (Dùng tiền lẻ).
*   **x=5, S=60:** Tận cùng là 0 (tròn chục) $\rightarrow$ **OK** (Khỏi cần tiền lẻ).

Bạn đã nắm vững "Điều kiện thắng". Bây giờ chúng ta sang mảnh ghép tiếp theo để tìm ra đáp án nhanh nhất.

---

## 🔄 CHUNK 2: CHIẾN THUẬT TRUY TÌM (THE LOOP)

Đề bài yêu cầu tìm số xẻng **ít nhất**.
Vì chúng ta không biết trước phải mua bao nhiêu cái, cách đơn giản và hiệu quả nhất là **"Thử từng cái một"**.

Giống như bạn đi thử chìa khóa vào ổ vậy:
1.  Thử mua 1 cái ($x=1$) $\rightarrow$ Tính tổng tiền $\rightarrow$ Kiểm tra đuôi.
    *   Nếu đúng: Dừng lại ngay! (Đây là đáp án nhỏ nhất).
    *   Nếu sai: Thử tiếp 2 cái ($x=2$).
2.  Lặp lại cho đến khi tìm thấy.

Để máy tính "nhìn" được chữ số tận cùng, chúng ta dùng phép toán **Chia lấy dư cho 10** (Modulus `% 10`).
*   Ví dụ: $48 \% 10 = 8$
*   Ví dụ: $60 \% 10 = 0$

---

### ⚠️ Cạm bẫy (Trap)
Nhiều bạn lo lắng: *"Nhỡ thử mãi không tìm được thì sao? Nhỡ nó chạy đến vô tận thì sao?"*

**Yên tâm:** Vì chúng ta chỉ quan tâm đến chữ số tận cùng (0 đến 9), quy luật của các con số sẽ lặp lại. Trong bài toán này, thực tế bạn chỉ cần thử tối đa 10 lần là chắc chắn sẽ tìm ra đáp án. (Đây là toán học, nhưng bạn cứ tin vào chiến thuật "thử dai dẳng" này nhé).

---

### ❓ THỬ THÁCH TƯ DUY (MENTAL CHECK)

Bây giờ hãy làm một chiếc "máy tính chạy bằng cơm".
Đề bài: Giá xẻng **$k = 7$**, đồng xu lẻ **$r = 3$**.

Bạn hãy lần lượt thử từ $x=1$ tăng dần lên. Hãy liệt kê quá trình thử của bạn cho đến khi tìm ra đáp án:

*   $x=1 \rightarrow S=7$ (Tận cùng 7) $\rightarrow$ Sai ($7 \neq 0$ và $7 \neq 3$)
*   $x=2 \rightarrow S=14$ (Tận cùng 4) $\rightarrow$ Sai
*   $x=3 \rightarrow S=...$ ?

Hãy viết tiếp chuỗi trên cho đến khi bạn tìm được $x$ thỏa mãn điều kiện (Tận cùng là 0 hoặc 3). Đáp án $x$ bằng bao nhiêu?	

Bingo! 🎯

Bạn tính rất chuẩn.
Với **9** cái xẻng, tổng tiền là **63**.
Chữ số tận cùng là **3** $\rightarrow$ Trùng khớp với đồng xu lẻ $r=3$.
Vậy chúng ta dừng lại và mua 9 cái.

---

## 🏁 CHUNK 3: TỔNG KẾT & MÃ GIẢ (WRAP UP)

Chúng ta đã có đầy đủ các mảnh ghép để dạy máy tính làm việc này.

### 📜 Thuật toán (Algorithm)
1.  **Nhập** giá xẻng `k` và đồng xu `r`.
2.  Tạo một vòng lặp đếm số xẻng `i` bắt đầu từ 1, 2, 3... tăng dần mãi.
3.  Ở mỗi bước, tính: `Tổng tiền = k * i`.
4.  **Kiểm tra:**
    *   Nếu `Tổng tiền` chia hết cho 10 (`% 10 == 0`) $\rightarrow$ **CHỌN**.
    *   HOẶC Nếu `Tổng tiền` chia 10 dư `r` (`% 10 == r`) $\rightarrow$ **CHỌN**.
5.  Nếu chọn được rồi thì in số `i` ra và **DỪNG LẠI NGAY** (Thoát vòng lặp).

### 📝 Mã giả (Pseudocode)

```text
Đọc k, r

Cho i chạy từ 1 đến vô tận:
    S = k * i
    duoi = S % 10  // Lấy chữ số tận cùng

    Nếu (duoi == 0) HOẶC (duoi == r):
        In ra i
        Dừng vòng lặp (Break)
```

---

### 🎓 BÀI TẬP VỀ ĐÍCH (FINAL CHECK)
Trước khi tôi đưa bạn xem code C++/Python mẫu, hãy xác nhận một điều nhỏ về cú pháp logic:

Trong lập trình, điều kiện **"Hoặc"** được viết là gì?
A. `&&`
B. `||`

Chọn đáp án đúng để mở khóa Code mẫu nhé! 🔓