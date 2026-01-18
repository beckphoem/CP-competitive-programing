Chào mừng bạn đến với lớp học tư duy thuật toán! 🤖 Tôi đã kích hoạt chế độ **Coach LHTL (Learning How to Learn)**.

Hôm nay chúng ta sẽ xử lý bài toán **Codeforces 581A - Vasya the Hipster**.

Đừng vội code! Hãy cất bàn phím đi. Chúng ta sẽ "mổ xẻ" bài toán này trước.

---

### 1. TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

**📝 Tóm tắt đề bài (Ngôn ngữ con người):**
Bạn có 2 đống tất (vớ):
*   Đống màu Đỏ có số lượng là $a$.
*   Đống màu Xanh có số lượng là $b$.

Nhiệm vụ của bạn là tính ra 2 con số:
1.  **Số ngày "sành điệu":** Mỗi ngày mang 1 chiếc Đỏ + 1 chiếc Xanh (cho đến khi không thể mang kiểu này được nữa).
2.  **Số ngày "thường thường":** Sau khi hết ngày sành điệu, bạn lấy số tất còn thừa (chắc chắn chỉ còn 1 màu) để mang cặp (2 chiếc cùng màu).

**🗺️ Lộ trình tư duy:**
*   **Chunk 1:** Tìm số lượng cặp "Sành điệu" (Khác màu).
*   **Chunk 2:** Xử lý đống tất thừa để tính số ngày "Thường thường" (Cùng màu).

Bạn đã sẵn sàng đi vào mảnh ghép đầu tiên chưa?

---

### 2. VÒNG LẶP TƯ DUY - CHUNK 1: CẶP ĐÔI HOÀN HẢO

**💡 Logic (Ẩn dụ hóa):**
Hãy tưởng tượng đây là một sàn khiêu vũ.
*   Phe Đỏ có $a$ người.
*   Phe Xanh có $b$ người.
*   Để nhảy điệu "Sành điệu", bắt buộc phải ghép **1 người Đỏ** với **1 người Xanh**.

Cuộc vui sẽ dừng lại ngay khi **một trong hai phe hết người**. Vậy số cặp nhảy được tạo ra phụ thuộc vào phe nào? Phe đông người hơn hay phe ít người hơn?

**⚠️ Bẫy tư duy (Trap):**
Nhiều bạn nghĩ phức tạp hóa vấn đề bằng vòng lặp `while`. Nhưng thực tế đây là một phép so sánh đơn giản.

**❓ Thử thách tư duy (Mental Check):**
Giả sử:
*   Đống tất Đỏ ($a$) = **7** chiếc.
*   Đống tất Xanh ($b$) = **4** chiếc.

**Câu hỏi:**
Bạn sẽ có bao nhiêu ngày "Sành điệu" (1 Đỏ + 1 Xanh)?
Tại sao lại là con số đó mà không phải số kia?

*(Tôi đang đợi câu trả lời của bạn...)*

**Chính xác!** 🎉

Bạn đã nắm được quy luật cốt lõi: **"Quyết định bởi kẻ yếu thế hơn"**.
Trong lập trình, chúng ta gọi đây là tìm giá trị nhỏ nhất: `min(a, b)`.

Chúng ta đã giải quyết xong con số đầu tiên (Output 1). Giờ hãy xử lý phần còn lại.

---

### 3. VÒNG LẶP TƯ DUY - CHUNK 2: VÉT SẠCH KHO (LEFTOVERS)

**💡 Logic (Tư duy trừu tượng):**
Sau khi "bữa tiệc" sành điệu kết thúc (4 cặp đã rời đi), hiện trạng kho tất như sau:
*   Phe Xanh: Hết sạch (vì nó ít hơn).
*   Phe Đỏ: Vẫn còn dư.

Số lượng tất còn dư chính là: **Hiệu số giữa hai đống** (Lấy đống lớn trừ đống bé).

Bây giờ, bạn bước vào giai đoạn "Thường thường":
*   Bạn chỉ còn lại một đống tất cùng màu (toàn màu Đỏ trong ví dụ trên).
*   Luật chơi mới: Cứ **2 chiếc** ghép lại thành 1 đôi để mang 1 ngày.

**⚠️ Bẫy tư duy (Trap):**
*   Nếu còn dư 1 chiếc lẻ loi thì sao? Bạn không thể mang 1 chiếc ra đường được. Chiếc lẻ đó sẽ bị bỏ đi. Đây là phép **chia lấy phần nguyên** (Integer Division).

**❓ Thử thách tư duy (Mental Check):**
Vẫn với ví dụ cũ: Đỏ ($a$) = **7**, Xanh ($b$) = **4**.

1.  Còn dư lại bao nhiêu chiếc tất (sau khi đã lấy 4 cặp sành điệu)?
2.  Từ số tất dư đó, bạn ghép được thêm **bao nhiêu cặp** cùng màu nữa?

*(Hãy cho tôi con số cuối cùng của câu 2)*

**Chuẩn không cần chỉnh!** 👏

Bạn đã hoàn thành xuất sắc các mảnh ghép tư duy.
*   Dư 3 chiếc $\rightarrow$ Ghép được 1 đôi $\rightarrow$ Còn 1 chiếc lẻ bị "ra rìa" (bỏ đi).
*   Trong lập trình, phép tính $3 \div 2 = 1$ (bỏ phần dư) chính là bản chất của phép chia số nguyên.

---

### 4. TỔNG KẾT & CHỐT THUẬT TOÁN (THE GRAND FINALE)

Chúng ta đã có đủ nguyên liệu. Hãy lắp ráp lại thành một công thức tổng quát cho máy tính hiểu nhé.

**🧩 Sơ đồ logic (Algorithm Flow):**

1.  **Input:** Nhập $a$ (Đỏ) và $b$ (Xanh).
2.  **Bước 1 (Tính ngày Sành điệu):**
    *   Tìm số nhỏ hơn trong hai số.
    *   Công thức: `sanh_dieu = min(a, b)`
3.  **Bước 2 (Tính tất thừa):**
    *   Tìm chênh lệch giữa hai đống.
    *   Công thức: `phan_thua = abs(a - b)` (Trị tuyệt đối của hiệu) hoặc `max(a, b) - min(a, b)`.
4.  **Bước 3 (Tính ngày Thường thường):**
    *   Lấy phần thừa chia đôi.
    *   Công thức: `thuong_thuong = phan_thua / 2` (Máy tính tự động lấy phần nguyên).
5.  **Output:** In ra `sanh_dieu` và `thuong_thuong`.

---

**💻 MÃ GIẢ (PSEUDOCODE) - C++ Style:**

```cpp
// Nhập a, b
cin >> a >> b;

// Tính toán
int days_fashion = min(a, b);
int remaining_socks = abs(a - b); // Cần thư viện <cmath> hoặc tự if/else
int days_boring = remaining_socks / 2;

// Kết quả
cout << days_fashion << " " << days_boring;
```

**🚀 BƯỚC CUỐI CÙNG:**
Bạn hãy thử viết code hoàn chỉnh (bằng C++, Python hoặc ngôn ngữ bạn chọn) và nộp thử (Submit) xem có xanh (Accepted) không nhé?

Nếu gặp lỗi hoặc muốn phân tích bài mới, cứ gọi tôi! **"Coach, bài tiếp theo!"** 👊