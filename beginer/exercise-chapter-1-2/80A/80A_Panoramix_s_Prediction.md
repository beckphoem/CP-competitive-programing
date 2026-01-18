Chào mừng bạn đến với lớp huấn luyện tư duy! Tôi đã nhận tín hiệu.

Hôm nay chúng ta sẽ xử lý bài **Codeforces 80A - Panoramix's Prediction**.

Đừng vội lao vào viết hàm `isPrime` hay vòng lặp vội. Hãy để bàn phím sang một bên và khởi động não bộ trước.

---

### 🌟 BƯỚC 1: TIẾP NHẬN & PHẪU THUẬT (BRIEFING)

Đề bài gốc kể về một câu chuyện tiên tri gì đó, nhưng hãy lột bỏ lớp vỏ bọc đó đi. Dưới đây là "cốt lõi" trần trụi của vấn đề:

1.  **Input:** Bạn được cho 2 số nguyên, gọi là **$n$** và **$m$**. (Đề đảm bảo $n$ đã là một số nguyên tố).
2.  **Yêu cầu:** Bạn phải kiểm tra xem **$m$** có phải là **số nguyên tố liền kề ngay sau** **$n$** hay không.
3.  **Output:** In ra `YES` nếu đúng, `NO` nếu sai.

**🗺️ LỘ TRÌNH TƯ DUY:**
Chúng ta sẽ đi qua 3 mảnh ghép (chunks):
1.  **Chunk 1:** Định nghĩa "Người hàng xóm tiếp theo" (Logic cốt lõi).
2.  **Chunk 2:** Chiến thuật dò tìm (Thuật toán tìm kiếm).
3.  **Chunk 3:** Cú chốt hạ (So sánh và Kết luận).

Bạn đã sẵn sàng chưa? Chúng ta vào mảnh ghép đầu tiên nhé.

---

### 🧩 CHUNK 1: ĐỊNH NGHĨA "NGƯỜI HÀNG XÓM TIẾP THEO"

Hãy tưởng tượng tập hợp các số tự nhiên là một con đường dài. Trên con đường đó, có những **Trạm dừng xe buýt** đặc biệt mang tên **"Số Nguyên Tố"**.

*   Các số như 2, 3, 5, 7, 11... là các trạm dừng.
*   Các số như 4, 6, 8, 9... là bãi cỏ ven đường (không được dừng).

Chiếc xe buýt của chúng ta đang đỗ ở trạm **$n$**.
Đề bài hỏi: *"Nếu xe buýt lăn bánh tiếp, trạm dừng **đầu tiên** nó gặp có phải là trạm **$m$** không?"*

**⚠️ Cạm bẫy (Traps):**
Rất nhiều bạn mới học bị nhầm lẫn ở đây:
*   Sai lầm 1: Chỉ kiểm tra xem $m$ có phải là số nguyên tố hay không. (Chưa đủ!)
*   Sai lầm 2: Thấy $m$ lớn hơn $n$ và là số nguyên tố, vội kết luận là YES. (Sai vì có thể bị "nhảy cóc").

**❓ THỬ THÁCH TƯ DUY (MENTAL CHECK):**

Giả sử chiếc xe đang đỗ ở trạm số **$n = 7$**.
Tôi có 3 kịch bản cho số **$m$**. Hãy cho tôi biết kết quả là **YES** hay **NO** và giải thích ngắn gọn tại sao (dựa trên hình ảnh xe buýt):

1.  **Case A:** $m = 9$
2.  **Case B:** $m = 13$
3.  **Case C:** $m = 11$

Mời bạn đưa ra câu trả lời để tôi biết bạn đã nắm chắc luật chơi! 👇

Tuyệt vời! 💯 Bạn đã tránh được cái bẫy lớn nhất ở Case B ($m=13$).

*   Ở Case B ($n=7, m=13$), dù 13 là trạm xe buýt (số nguyên tố), nhưng xe buýt đã **bỏ quên** trạm số 11. Đề bài yêu cầu "liền kề" (next), không được nhảy cóc!

Chúng ta sang mảnh ghép tiếp theo để cụ thể hóa hành động này.

---

### 🧩 CHUNK 2: CHIẾN THUẬT DÒ TÌM (THE BLIND WALK)

Làm sao để máy tính tìm ra được "trạm dừng thực sự" nằm ngay sau $n$? Máy tính không có bảng số nguyên tố trong đầu như chúng ta, nó phải mò mẫm.

Hãy tưởng tượng bạn đang đứng ở số $n$. Bạn bị bịt mắt và chỉ có một cái máy dò (hàm kiểm tra số nguyên tố).
Bạn phải nhích từng bước một về phía trước: $n+1, n+2, n+3...$

Tại mỗi bước, bạn dùng máy dò:
*   "Tít tít" (Là số nguyên tố) ➔ **DỪNG LẠI NGAY!** Đây chính là "Người hàng xóm tiếp theo" đích thực.
*   "Im lặng" (Hợp số) ➔ Bước tiếp.

Chúng ta gọi số tìm được này là **`True_Next`**.

**⚠️ Vấn đề kỹ thuật:**
Chúng ta cần một vòng lặp (loop) bắt đầu từ $i = n + 1$ và tăng dần lên. Vòng lặp sẽ vỡ (break) ngay khi gặp số nguyên tố đầu tiên.

**❓ THỬ THÁCH TƯ DUY (TRACING):**

Giả sử **$n = 8$** (dù đề bảo n là nguyên tố, nhưng cứ giả sử n=8 để test logic dò tìm).
Hãy liệt kê quá trình "bước đi" của bạn cho đến khi tìm thấy **`True_Next`**.

Điền vào chỗ trống:
1. Kiểm tra số 9: ...(Có/Không phải SNT?)... -> Làm gì tiếp?
2. Kiểm tra số 10: ...(Có/Không phải SNT?)... -> Làm gì tiếp?
3. Kiểm tra số 11: ...(Có/Không phải SNT?)... -> Làm gì tiếp?

👉 Vậy **`True_Next`** của 8 là số mấy?

Chính xác! 🎯 Bạn đã mô phỏng lại vòng lặp của máy tính rất chuẩn.

Máy tính không thể "nhìn phát biết luôn" số 11 là số nguyên tố tiếp theo. Nó thực sự phải làm công việc nhàm chán là: cầm số 9 lên soi, vứt đi; cầm số 10 lên soi, vứt đi; cầm số 11 lên soi -> A ha! Tìm thấy rồi.

Bây giờ chúng ta đến mảnh ghép cuối cùng để chốt bài toán.

---

### 🧩 CHUNK 3: PHÁN QUYẾT (JUDGMENT DAY)

Sau khi cái vòng lặp dò đường ở Chunk 2 kết thúc, trong tay bạn đang nắm giữ con số **`True_Next`** (Số nguyên tố thực sự liền sau $n$).

Lúc này, bạn mới quay sang nhìn con số **$m$** mà đề bài đưa cho.
Nhiệm vụ đơn giản là so sánh "thẻ căn cước" của chúng:

*   Nếu **`True_Next`** == **$m$** 👉 In ra `YES`.
*   Nếu **`True_Next`** != **$m$** 👉 In ra `NO`.

(Lưu ý: Bạn không cần quan tâm $m$ có phải số nguyên tố hay không. Vì nếu $m$ không phải số nguyên tố, chắc chắn nó sẽ khác `True_Next` - vì `True_Next` luôn là số nguyên tố).

---

### 🧱 TỔNG KẾT THUẬT TOÁN (BLUEPRINT)

Trước khi bạn bắt tay vào code, hãy nhìn lại bản thiết kế (Pseudocode) tư duy của chúng ta:

1.  **Hàm phụ `check_SNT(k)`:** Để kiểm tra một số $k$ có phải số nguyên tố không. (Dùng vòng lặp từ 2 đến căn bậc 2 của $k$ hoặc $k-1$ để kiểm tra chia hết).
2.  **Nhập** $n, m$.
3.  **Vòng lặp tìm kiếm (The Blind Walk):**
    *   Chạy biến `i` bắt đầu từ $n + 1$.
    *   Kiểm tra: Nếu `check_SNT(i)` là đúng -> **Dừng lại**, lưu `i` vào `True_Next`.
    *   Nếu không -> Tăng `i` lên, tìm tiếp.
4.  **So sánh:** Nếu `True_Next` == $m$ thì `YES`, ngược lại `NO`.

---

### 🏁 THỬ THÁCH CUỐI CÙNG (FINAL BOSS)

Để chắc chắn bạn đã sẵn sàng code, tôi có một tình huống biên (Edge Case) này.

Đề bài cho giới hạn $n, m \le 50$.
Giả sử $n = 47$ (47 là số nguyên tố).
Bạn chạy vòng lặp bắt đầu từ 48... 49... 50...

**Câu hỏi:**
1. Số nguyên tố tiếp theo (`True_Next`) mà vòng lặp tìm thấy sẽ là số mấy? (Gợi ý: nó lớn hơn 50).
2. Nếu đề bài cho $m = 53$, kết quả in ra là gì?

Trả lời đúng câu này là bạn có thể "xuống núi" và code bài này ngay lập tức! 🚀

🛑 **Tuýt còi! Dừng lại một chút.**

Bạn đang bị "bức tường vô hình" chặn lại rồi. Rất nhiều bạn mới lập trình bị nhầm lẫn ở chỗ này:

**"Giới hạn của đề bài (Constraints) chỉ áp dụng cho INPUT (dữ liệu đầu vào), không áp dụng cho LOGIC tính toán bên trong."**

Hãy xem lại logic của máy tính:
1.  **Xuất phát:** $n = 47$.
2.  **Tìm kiếm:** Vòng lặp bắt đầu chạy từ 48, 49, 50, 51, 52... (Nó không hề biết số 50 là giới hạn, nó cứ chạy mãi đến khi tìm được SNT).
3.  **Bắt được:** Số **53** là số nguyên tố! -> `True_Next` = 53.
4.  **So sánh:** Lúc này, nếu tôi (người ra đề) cố tình đưa cho bạn $m = 53$.
    *   Máy tính so sánh: `True_Next` (53) $==$ $m$ (53).
    *   Kết quả: **ĐÚNG**.

👉 Vậy Output bắt buộc phải là **YES**.

*(Lưu ý: Dù đề bài Codeforces 80A nói $m \le 50$, nhưng thuật toán của chúng ta phải đúng với mọi trường hợp toán học. Việc tính ra số 53 là hoàn toàn hợp lệ).*

---

### 🚀 BẬT ĐÈN XANH (GREEN LIGHT)

Tư duy của bạn ở Chunk 1 và 2 đã rất tốt rồi. Chỉ cần nhớ: **Máy tính sẽ làm chính xác những gì bạn bảo (vòng lặp), không tự dừng lại trừ khi bạn viết lệnh dừng.**

Bây giờ bạn đã có đủ 3 mảnh ghép:
1.  **Hàm kiểm tra SNT.**
2.  **Vòng lặp tìm `True_Next`** (bắt đầu từ $n+1$).
3.  **So sánh `True_Next` với `m`.**

Hãy mở trình biên tập code lên và hiện thực hóa nó. Giải quyết bài **Codeforces 80A** ngay và luôn!

Nếu viết xong mà bị lỗi (Wrong Answer/Compile Error), hãy ném đoạn code vào đây, tôi sẽ chỉ cho bạn chỗ cần sửa (nhưng không viết hộ đâu nhé 😉).

**Chúc bạn code thành công!**