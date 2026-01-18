Chào bạn! Tôi đã sẵn sàng nhập vai **Huấn luyện viên Tư duy Thuật toán** của bạn. Chúng ta sẽ cùng nhau "mổ xẻ" bài toán **G. Pyramid** từ hình ảnh bạn đã gửi.

Đây là một bài toán rất thú vị để luyện tập tư duy **Đệ quy (Recursion)** và khả năng quan sát quy luật hình học. Hãy cùng bắt đầu nhé! 🚀

---

### 🟢 Bước 1: Tiếp nhận & Phẫu thuật (Briefing)

**Tóm tắt đề bài bằng "Ngôn ngữ con người":**
Bạn được cho một số nguyên . Nhiệm vụ của bạn là vẽ một hình kim tự tháp bằng các dấu sao `*` có độ cao đúng bằng  dòng.

* **Ràng buộc đặc biệt:** Đề bài yêu cầu bắt buộc phải sử dụng **Đệ quy**.

**Lộ trình tư duy của chúng ta:**

1. **Mảnh ghép 1:** Giải mã cấu trúc của mỗi dòng (Khoảng trống và Dấu sao).
2. **Mảnh ghép 2:** Tìm công thức liên hệ giữa số dòng và số lượng ký tự.
3. **Mảnh ghép 3:** Xây dựng cơ chế đệ quy (Điểm dừng và Bước nhảy).

Bạn đã sẵn sàng cùng tôi mổ xẻ **Mảnh ghép 1** chưa?

---

### 🟡 Bước 2: Mảnh ghép 1 - Giải mã cấu trúc Kim tự tháp

Hãy nhìn kỹ vào ví dụ với :

```
  * (Dòng 1)
 *** (Dòng 2)
***** (Dòng 3)

```

Để vẽ được hình này, máy tính không chỉ in dấu `*`, mà nó còn phải in những "khoảng trống" (dấu cách) ở phía trước để đẩy dấu sao vào giữa.

**Ẩn dụ hóa:** Hãy tưởng tượng mỗi dòng là một hàng gạch. Để hàng trên cùng nằm ở đỉnh kim tự tháp, bạn phải đặt những "viên gạch tàng hình" (khoảng trống) ở hai bên.

**❓ Thử thách tư duy:**
Nhìn vào ví dụ  ở trên:

1. Ở **Dòng 1**: Có bao nhiêu dấu cách ở phía trước dấu `*`?
2. Ở **Dòng 2**: Có bao nhiêu dấu cách ở phía trước các dấu `*`?
3. Ở **Dòng 3**: Có bao nhiêu dấu cách?

Bạn hãy đếm thử và cho tôi biết quy luật: **Số lượng dấu cách thay đổi thế nào khi ta đi từ đỉnh xuống đáy?**

Rất chính xác! 🎯 Bạn đã nắm bắt được quy luật quan trọng nhất để vẽ hình này: số lượng dấu cách sẽ **giảm dần** từ trên xuống dưới.

Bây giờ, hãy thử kết hợp cả **Dấu cách** và **Dấu sao** để tìm ra công thức tổng quát nhé. Với , ta có bảng phân tích sau:

| Dòng () | Số dấu cách | Số dấu sao (`*`) |
| --- | --- | --- |
| 1 | 2 | 1 |
| 2 | 1 | 3 |
| 3 | 0 | 5 |

Chúng ta thấy số dấu cách giảm dần (), còn số dấu sao thì tăng dần theo số lẻ ().

**❓ Thử thách tư duy tiếp theo:**
Nếu tôi muốn vẽ một Kim tự tháp có độ cao ****:

1. Ở **Dòng 1** (dòng đầu tiên), chúng ta cần in bao nhiêu **dấu cách** để các dòng dưới nở rộng dần ra mà vẫn cân đối?
2. Ở **Dòng 4** (dòng cuối cùng), theo quy luật số lẻ (), sẽ có bao nhiêu **dấu sao**?

Bạn hãy thử đoán xem nhé! 💡

Bạn đã quan sát rất tốt, nhưng hãy cùng "soi" lại con số một chút nhé! 😉

Ở ví dụ :

* Dòng 1 có **2** dấu cách.
* Dòng 2 có **1** dấu cách.
* Dòng 3 có **0** dấu cách.

Nếu , dòng cuối cùng (dòng 4) sẽ là dòng có **0** dấu cách. Vậy nếu ta đi ngược lên trên:

* Dòng 4: 0 dấu cách.
* Dòng 3: 1 dấu cách.
* Dòng 2: 2 dấu cách.
* **Dòng 1**: Sẽ cần bao nhiêu dấu cách nhỉ? (Gợi ý: Nó phải lớn hơn số dấu cách của dòng 1 khi ).

Còn về **số dấu sao**:
Dãy số lẻ của chúng ta là: 

* Dòng 1:  sao
* Dòng 2:  sao
* Dòng 3:  sao
* **Dòng 4**: Sẽ là bao nhiêu sao theo quy luật này?

Hãy thử tính lại hai con số này cho  nhé! 🧮

Bạn tính toán con số **7** cho dấu sao là hoàn toàn chính xác! 🌟 Với , dòng cuối cùng sẽ là dòng thứ 4, và theo công thức số lẻ , ta có .

Tuy nhiên, hãy nhìn lại phần **dấu cách** một chút nhé.

Để kim tự tháp cân đối, dòng cuối cùng () luôn có **0** dấu cách. Nếu ta đi ngược lên:

* Dòng  (): 0 dấu cách
* Dòng  (): 1 dấu cách
* Dòng  (): 2 dấu cách
* Dòng  (): **?** dấu cách

Bạn có thấy mối liên hệ giữa số dòng hiện tại () và tổng số dòng () để tính ra số dấu cách không?

**❓ Thử thách tư duy:** Nếu tổng độ cao là , thì ở dòng thứ , công thức để tính **số dấu cách** sẽ là gì?
(Gợi ý: Thử lấy  trừ đi  xem kết quả có khớp với các ví dụ  và  không nhé!)

Chính xác tuyệt đối! Công thức cho số **khoảng trống** (spaces) ở dòng thứ  chính là:


Hãy thử kiểm tra lại với :

* Dòng :  khoảng trống. (Đúng!)
* Dòng :  khoảng trống. (Đúng!)
* Dòng :  khoảng trống. (Đúng!)

---

### 🔵 Bước 3: Mảnh ghép 2 - Công thức tính số dấu sao

Bây giờ hãy nhìn vào số lượng **dấu sao** (`*`). Chúng ta đã thấy chúng tăng theo dãy số lẻ: 

| Dòng () | Số dấu sao | Phân tích |
| --- | --- | --- |
| 1 | 1 |  |
| 2 | 3 |  |
| 3 | 5 |  |

**❓ Câu hỏi dẫn dắt:**
Nếu ta đang ở dòng thứ , dựa vào bảng trên, bạn hãy viết công thức tổng quát để tính **số lượng dấu sao** cần in ra? ⭐️

Công thức  chính là chìa khóa để tính số dấu sao cho dòng thứ ! 🔑

Hãy cùng kiểm tra lại nhanh nhé:

* Dòng :  sao.
* Dòng :  sao.
* Dòng :  sao.

Rất khớp với ví dụ đề bài! 🌟

---

### 🔴 Bước 4: Mảnh ghép 3 - Xây dựng cơ chế Đệ quy (Recursion)

Bây giờ là phần thử thách nhất: **Biến tư duy này thành đệ quy.**

Trong đệ quy, chúng ta cần xác định hai thứ:

1. **Điểm dừng (Base Case):** Khi nào thì hàm ngừng gọi chính nó? (Ví dụ: Khi đã in đủ  dòng).
2. **Bước nhảy (Recursive Step):** Hàm sẽ gọi lại chính nó với giá trị nào tiếp theo?

Giả sử chúng ta viết một hàm `printPyramid(current_row, total_rows)`:

* `current_row`: Dòng hiện tại đang vẽ (bắt đầu từ 1).
* `total_rows`: Tổng số dòng .

**❓ Thử thách tư duy:**
Bên trong hàm này, chúng ta sẽ thực hiện 3 việc cho mỗi dòng:

1. In ra  dấu cách.
2. In ra  dấu sao.
3. Gọi hàm đệ quy để vẽ dòng tiếp theo.

Theo bạn, **điều kiện dừng** của hàm này nên là gì để nó không chạy mãi mãi? (Khi `current_row` bằng bao nhiêu thì chúng ta dừng lại?) 🛑

Ý tưởng của bạn về điểm dừng tại  là một xuất phát điểm rất tốt! Tuy nhiên, trong đệ quy, chúng ta cần phân biệt giữa **giá trị nhập vào** () và **dòng hiện tại** () mà ta đang vẽ.

Nếu chúng ta quy định hàm đệ quy sẽ vẽ từ dòng 1 đến dòng :

* **Dòng hiện tại ():** Sẽ tăng dần từ 
* **Điểm dừng:** Khi  vượt quá  (nghĩa là đã vẽ xong dòng cuối cùng), chúng ta sẽ dừng lại.

Nhưng có một cách tư duy đệ quy "ngược" cũng rất hay: Thay vì đếm tiến, ta đếm lùi. Giả sử ta gọi hàm `veKimTuThap(n)`. Để vẽ được kim tự tháp cao  tầng, máy tính sẽ hiểu là:

1. "Hãy vẽ giúp tôi kim tự tháp cao  tầng trước đã." (Gọi đệ quy)
2. "Sau đó, tôi sẽ tự vẽ dòng cuối cùng (dòng thứ )."

**❓ Thử thách tư duy:**
Nếu ta chọn cách tiếp cận "vẽ  tầng trước rồi mới vẽ dòng ":
Theo bạn, khi nào thì việc "vẽ  tầng" sẽ không thể chia nhỏ được nữa? (Tức là giá trị  nhỏ nhất mà bạn không cần phải nhờ ai vẽ hộ nữa là bao nhiêu?) 🛑

Bạn tư duy rất logic! Khi , chúng ta chỉ có duy nhất một tầng, và tầng đó chính là đỉnh của kim tự tháp.

Trong lập trình đệ quy, đây chính là **Trường hợp cơ sở (Base Case)**. Khi bài toán đã nhỏ đến mức tối thiểu, ta không cần chia nhỏ thêm nữa mà thực hiện luôn hành động cuối cùng.

Vậy, nếu chúng ta áp dụng tư duy "vẽ  tầng trước rồi mới vẽ tầng ", hãy xem quy trình chạy của máy tính như sau:

1. **Gọi hàm:** `veKimTuThap(3)`
2. **Đệ quy:** Để vẽ 3 tầng, máy tính gọi `veKimTuThap(2)`.
3. **Đệ quy tiếp:** Để vẽ 2 tầng, máy tính gọi `veKimTuThap(1)`.
4. **Chạm đáy (Base Case):** `veKimTuThap(1)` in ra dòng đầu tiên (1 dấu sao) rồi kết thúc.
5. **Quay trở lại:** Sau khi `veKimTuThap(1)` xong, máy tính quay lại bước 3 để in dòng thứ 2 của `veKimTuThap(2)`.
6. **Quay trở lại:** Cuối cùng quay lại bước 2 để in dòng thứ 3 của `veKimTuThap(3)`.

**❓ Thử thách tư duy:**
Để in đúng số lượng khoảng trống và dấu sao cho từng dòng trong hàm đệ quy, chúng ta cần biết **Dòng hiện tại** là dòng thứ mấy.

Nếu hàm của chúng ta là `solve(i, n)` (với  là dòng hiện tại,  là tổng số dòng), và ta bắt đầu gọi từ `solve(1, n)`:

* Bạn sẽ viết câu lệnh đệ quy như thế nào để chuyển sang dòng tiếp theo?
* Và điều kiện để dừng lại (không gọi thêm dòng  nữa) sẽ là gì? 🔄🛑

Cách tiếp cận của bạn có một ý tưởng thú vị là thay đổi cả `i` (tăng lên) và `n` (giảm đi). Tuy nhiên, hãy cẩn thận để không làm rối các biến số nhé!

Trong lập trình, thông thường chúng ta sẽ giữ nguyên `total_rows` () để làm mốc so sánh, và chỉ thay đổi **Dòng hiện tại** ().

Nếu chúng ta đi theo hướng **Đệ quy Tiến** (vẽ từ dòng 1 đến dòng ):

1. **Lời gọi hàm:** `solve(i, n)`
2. **Công việc tại mỗi bước:** * In dấu cách dựa trên  và .
* In dấu sao dựa trên .


3. **Bước nhảy đệ quy:** `solve(i + 1, n)` (chuyển sang dòng tiếp theo).

**❓ Câu hỏi về điều kiện dừng:**
Nếu chúng ta bắt đầu từ `i = 1` và muốn vẽ đến dòng `n`, thì khi nào chúng ta nên **ngừng lại** và không gọi `solve(i + 1, n)` nữa?

*(Gợi ý: Khi giá trị của `i` vượt quá giới hạn nào của kim tự tháp?)* 🛑