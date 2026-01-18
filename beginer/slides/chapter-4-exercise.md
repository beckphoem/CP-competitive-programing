Dưới đây là toàn bộ nội dung bài báo cáo dưới dạng Raw Markdown để bạn dễ dàng sao chép:

# Báo cáo Chuyên sâu: Phương pháp Sư phạm và Phân tích Thuật toán cho 20 Bài tập Codeforces (Rating 800-900) Sử dụng Cấu trúc Vòng lặp While

## 1. Giới thiệu Tổng quan và Triết lý Sư phạm

Trong giáo dục khoa học máy tính, đặc biệt là giai đoạn nhập môn lập trình thi đấu (Competitive Programming), việc lựa chọn bài tập phù hợp với trình độ và công cụ kiến thức của học sinh là yếu tố quyết định sự thành công. Báo cáo này được xây dựng dựa trên yêu cầu cụ thể: tuyển chọn và phân tích 20 bài tập trên nền tảng Codeforces, nằm trong dải xếp hạng (rating) từ 800 đến 900 Elo (mức Newbie), với ràng buộc kỹ thuật nghiêm ngặt là chỉ sử dụng vòng lặp `while` và cấu trúc điều kiện `if-else`.

### 1.1. Tầm quan trọng của Vòng lặp `while` trong Tư duy Lập trình

Trước khi học sinh tiếp cận với vòng lặp `for` – một cấu trúc lặp xác định (definite iteration) thường che giấu các chi tiết về quản lý biến đếm – việc thành thạo vòng lặp `while` là bước đệm thiết yếu. Vòng lặp `while` đại diện cho tư duy lặp không xác định (indefinite iteration), nơi số lần lặp phụ thuộc hoàn toàn vào một điều kiện logic thay vì một bộ đếm cố định.

Việc giải quyết các bài toán bằng `while` buộc học sinh phải:

1. **Khởi tạo trạng thái thủ công:** Học sinh phải tự khai báo và thiết lập giá trị ban đầu cho các biến điều khiển.
2. **Kiểm soát luồng logic tường minh:** Điều kiện dừng (termination condition) phải được xây dựng rõ ràng dựa trên trạng thái hiện tại của bài toán.
3. **Cập nhật trạng thái chủ động:** Việc thay đổi biến điều khiển (như tăng biến đếm, chia nhỏ số liệu) phải được viết rõ trong thân vòng lặp, giúp tránh các lỗi logic ẩn thường gặp khi dùng `for`.



### 1.2. Phương pháp Tiếp cận và Cấu trúc Báo cáo

Báo cáo này không chỉ cung cấp lời giải, mà còn đi sâu vào phân tích sư phạm. Mỗi bài tập sẽ được mổ xẻ qua các khía cạnh:

* **Ngữ cảnh và Mục tiêu Giáo dục:** Tại sao bài toán này phù hợp để dạy `while`?
* **Phân tích Kỹ thuật:** Cách chuyển đổi tư duy từ công thức toán học hoặc vòng lặp `for` sang `while`.
* **Mô phỏng Trạng thái (Trace Tables):** Bảng chi tiết giá trị các biến qua từng bước lặp, giúp hình dung cách máy tính thực thi mã.
* **Cạm bẫy Thường gặp:** Các lỗi như lặp vô hạn (infinite loops) hay lỗi biên (off-by-one errors) mà học sinh mới thường mắc phải.

Dưới đây là phân tích chi tiết cho 20 bài tập được tuyển chọn.

---

## 2. Nhóm Bài tập Mô phỏng Sự Tăng trưởng và Tích lũy (Simulation & Accumulation)

Nhóm bài tập này là ứng cử viên hoàn hảo nhất cho việc giới thiệu vòng lặp `while`. Đặc điểm chung của chúng là chúng ta không biết trước cần bao nhiêu bước để đạt được mục tiêu; ta chỉ biết điều kiện dừng (ví dụ: "cho đến khi đầy", "cho đến khi lớn hơn").

### Bài 1: Bear and Big Brother (Mã bài: 791A)

**Nguồn dữ liệu:** Codeforces Round #405 (Div. 2).

#### Đề bài chi tiết

Limak và Bob là hai anh em gấu. Limak hiện tại nặng  kg và Bob nặng  kg (). Khả năng tăng trưởng của hai chú gấu khác nhau: sau mỗi năm, cân nặng của Limak tăng gấp ba lần, trong khi cân nặng của Bob chỉ tăng gấp đôi. Yêu cầu đặt ra là hãy xác định sau bao nhiêu năm nguyên (integer years), Limak sẽ trở nên nặng hơn Bob một cách nghiêm ngặt (tức là ).

#### Phân tích Sư phạm và Logic `While`

Đây là bài toán kinh điển về vòng lặp không xác định. Học sinh không thể dùng một công thức đơn giản để biết ngay số năm (trừ khi dùng logarit, điều chưa phù hợp ở trình độ này). Tư duy tự nhiên nhất là "thử từng năm một".

* **Tại sao dùng `while`?** Chúng ta không biết trước số năm cần tìm. Điều kiện duy trì vòng lặp là "khi Limak vẫn còn nhẹ hơn hoặc bằng Bob" (). Khi điều kiện này sai, tức là Limak đã nặng hơn, vòng lặp kết thúc.

#### Chiến lược Giải quyết

1. **Khởi tạo:** Đặt biến đếm `year = 0`. Đọc giá trị đầu vào `a` và `b`.
2. **Điều kiện lặp:** `while (a <= b)`. Logic này rất trực quan: chừng nào mục tiêu chưa đạt được (Limak chưa lớn hơn Bob), ta tiếp tục mô phỏng sự tăng trưởng.
3. **Cập nhật trạng thái:** Bên trong vòng lặp, thực hiện nhân `a` với 3 và `b` với 2. Đồng thời, tăng biến `year` lên 1 đơn vị.

#### Bảng Mô phỏng (Trace Table)

Giả sử input là .

| Bước lặp (Iteration) | Cân nặng Limak () | Cân nặng Bob () | Năm () | Điều kiện () | Hành động |
| --- | --- | --- | --- | --- | --- |
| Khởi tạo | 4 | 7 | 0 | `True` (4  7) | Vào vòng lặp |
| 1 |  |  | 1 | `True` (12  14) | Tiếp tục lặp |
| 2 |  |  | 2 | `False` (36 > 28) | Dừng vòng lặp |
| Kết quả | **36** | **28** | **2** | - | In ra 2 |

#### Nhận định Chuyên sâu

Bài toán này giúp học sinh phân biệt rõ ràng giữa điều kiện lặp () và điều kiện kết quả (). Một lỗi thường gặp là học sinh dùng `while (a < b)`, dẫn đến sai sót khi  bằng  sau một số năm. Việc sử dụng `while` giúp củng cố tư duy về bất đẳng thức trong điều kiện dừng.

---

### Bài 2: Vanya and Cubes (Mã bài: 492A)

**Nguồn dữ liệu:** Codeforces Round #280 (Div. 2).

#### Đề bài chi tiết

Vanya nhận được  khối lập phương. Anh ấy muốn xây dựng một kim tự tháp. Tầng trên cùng (tầng 1) cần 1 khối. Tầng thứ 2 cần  khối. Tổng quát, tầng thứ  cần số khối bằng tổng các số nguyên từ 1 đến  (tức là ). Hãy tìm chiều cao lớn nhất  của kim tự tháp mà Vanya có thể xây được với  khối cho trước.

#### Phân tích Sư phạm và Logic `While`

Bài toán này phức tạp hơn vì nó liên quan đến hai lớp tích lũy:

1. Số khối cần cho tầng hiện tại (tăng dần theo cấp số cộng).
2. Tổng số khối đã sử dụng cho toàn bộ kim tự tháp.

Sử dụng `while` là phương pháp tiếp cận mô phỏng "tham lam" (greedy): ta cứ xây thêm tầng miễn là còn đủ gạch.

#### Chiến lược Giải quyết

1. **Khởi tạo:**
* `n`: Tổng số khối đang có.
* `height = 0`: Chiều cao hiện tại.
* `current_level_needs = 0`: Số khối cần cho tầng tiếp theo.


2. **Điều kiện lặp:** Ở đây có một sự tinh tế. Ta có thể dùng `while` với điều kiện kiểm tra xem số gạch còn lại có đủ cho tầng tiếp theo hay không. Tuy nhiên, cách dễ hiểu hơn cho học sinh mới là "trừ dần và kiểm tra".
* Cách tiếp cận: `while (n >= 0)` sau đó xử lý việc bị âm, hoặc kiểm tra trước khi trừ.
* Phương án tối ưu cho học sinh: Sử dụng biến phụ để tính gạch cần thiết, so sánh trong `while`.


3. **Thuật toán chi tiết:**
* Biến `cnt = 0` (số gạch cần cho tầng hiện tại).
* Biến `h = 0`.
* `while (n >= 0)`:
* Tăng chiều cao dự kiến `h = h + 1`.
* Tính số gạch tầng này: `cnt = cnt + h`.
* Kiểm tra: Nếu `n >= cnt`, thì `n = n - cnt`.
* Nếu `n < cnt`: Dừng lại (break) hoặc dùng cờ hiệu.


* Tuy nhiên, để tuân thủ "không dùng break" nếu chưa học, ta có thể thiết kế điều kiện `while` phức tạp hơn: `while (true)` kết hợp logic kiểm tra, hoặc tính toán trước.


*Cách tiếp cận `while` chuẩn mực nhất:*
* `h = 0`
* `next_level_cost = 1`
* `used = 0`
* `while (used + next_level_cost <= n)`:
* `used = used + next_level_cost`
* `h = h + 1`
* `next_level_cost = next_level_cost + (h + 1)` (Số gạch tầng sau luôn bằng số gạch tầng này cộng thêm chỉ số tầng mới).





#### Bảng Mô phỏng (Trace Table)

Giả sử .

| Bước | Chiều cao () | Gạch cần tầng tới () | Tổng đã dùng () | Điều kiện () | Hành động |
| --- | --- | --- | --- | --- | --- |
| Start | 0 | 1 | 0 | `True` () | Vào lặp |
| 1 | 1 |  | 1 | `True` () | Tiếp tục |
| 2 | 2 |  |  | `False` () | Dừng |
| Kết quả | **2** | - | - | - | In ra 2 |

#### Nhận định Chuyên sâu

Bài toán này dạy học sinh về sự "tăng tốc" của các dãy số (tầng 1 cần 1, tầng 2 cần 3, tầng 3 cần 6...). Vòng lặp `while` giúp kiểm soát chặt chẽ giới hạn tài nguyên (), ngăn chặn việc "xây lố" số tầng khi không đủ gạch.

---

### Bài 3: Wrong Subtraction (Mã bài: 977A)

**Nguồn dữ liệu:** Codeforces Round #479 (Div. 3).

#### Đề bài chi tiết

Tanya thực hiện giảm giá trị của một số nguyên dương  đi  lần. Thuật toán giảm của Tanya không phải là phép trừ thông thường:

* Nếu chữ số cuối cùng của  khác 0, cô ấy giảm  đi 1 ().
* Nếu chữ số cuối cùng của  là 0, cô ấy chia  cho 10 ().
Hãy in ra kết quả cuối cùng sau khi thực hiện  lần thao tác trên.

#### Phân tích Sư phạm và Logic `While`

Mặc dù số lần lặp là xác định ( lần), nhưng việc sử dụng `while` ở đây rất tự nhiên để mô phỏng quá trình đếm ngược. Nó chuyển đổi tư duy từ "lặp từ 1 đến k" (của `for`) sang "làm việc này khi k vẫn còn lớn hơn 0" (của `while`).

#### Chiến lược Giải quyết

1. **Khởi tạo:** Đọc  và .
2. **Điều kiện lặp:** `while (k > 0)`. Mỗi lần thực hiện một thao tác, ta giảm  đi 1. Vòng lặp dừng khi .
3. **Logic rẽ nhánh (`if-else`):**
* Bên trong `while`, kiểm tra chữ số cuối bằng phép chia dư: `last_digit = n % 10`.
* Nếu `last_digit!= 0`: `n = n - 1`.
* Nếu `last_digit == 0`: `n = n / 10`.
* Đừng quên: `k = k - 1`.



#### Bảng Mô phỏng (Trace Table)

Giả sử .

| Lần lặp | Giá trị  | Chữ số cuối () | Hành động | Giá trị  sau bước |
| --- | --- | --- | --- | --- |
| 1 | 512 | 2 () |  | 3 |
| 2 | 511 | 1 () |  | 2 |
| 3 | 510 | 0 () |  | 1 |
| 4 | 51 | 1 () |  | 0 (Dừng) |

#### Nhận định Chuyên sâu

Bài tập này kết hợp hoàn hảo giữa `while` và `if-else`. Nó cũng giới thiệu khái niệm thay đổi dữ liệu đầu vào theo các quy tắc khác nhau (conditional modification). Học sinh học được cách thao tác trên chữ số tận cùng, một kỹ thuật nền tảng cho các bài toán số học sau này.

---

## 3. Nhóm Bài tập Về Tách Số và Xử lý Chữ số (Digit Extraction)

Đây là nhóm bài tập mà vòng lặp `while` thể hiện sự vượt trội tuyệt đối so với `for`. Khi xử lý các chữ số của một số nguyên (ví dụ: tính tổng chữ số), ta không biết trước số đó có bao nhiêu chữ số. Điều kiện dừng tự nhiên là `while (n > 0)`.

### Bài 4: Near Lucky Number (Mã bài: 110A)

**Nguồn dữ liệu:** Codeforces Beta Round #84 (Div. 2 Only).

#### Đề bài chi tiết

Một số nguyên dương được gọi là "số may mắn" (lucky number) nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ: 47, 744, 4 là số may mắn; 5, 17, 467 không phải.
Nhiệm vụ: Cho một số nguyên  (có thể lên đến ). Hãy đếm số lượng chữ số may mắn trong . Nếu *số lượng* đó là một số may mắn, in "YES", ngược lại in "NO".

#### Phân tích Sư phạm và Logic `While`

Học sinh thường nhầm lẫn giữa việc kiểm tra  có phải số may mắn không và việc kiểm tra *số lượng chữ số* may mắn. Bài toán yêu cầu duyệt qua từng chữ số của . Vì  rất lớn (), ta không thể dùng chuỗi nếu chưa học, mà phải dùng phép chia và chia dư với kiểu dữ liệu `long long`.

#### Chiến lược Giải quyết

1. **Khởi tạo:** Biến `n` kiểu `long long` (C++). Biến đếm `count = 0`.
2. **Vòng lặp tách số:** `while (n > 0)`.
* Lấy chữ số cuối: `digit = n % 10`.
* Kiểm tra: `if (digit == 4 |



| digit == 7)`thì`count = count + 1`. *   Loại bỏ chữ số cuối: `n = n / 10`. 3.  **Kiểm tra kết quả:** Sau khi vòng lặp kết thúc, ta có `count`(thường nhỏ, vì $n$ có tối đa 18-19 chữ số). *   Kiểm tra xem`count`có phải là số may mắn không (tức là`count`bằng 4 hoặc 7... thực tế với $n \le 10^{18}$, số chữ số tối đa là 19, nên số lượng chữ số may mắn chỉ có thể là 4 hoặc 7. Các số may mắn tiếp theo như 44, 47 đều lớn hơn 19). *  `if (count == 4 |

| count == 7)` in "YES", else "NO".

#### Bảng Mô phỏng

Giả sử .

| Bước |  |  () | Điều kiện (4 or 7?) | `count` |  mới () |
| --- | --- | --- | --- | --- | --- |
| 1 | 40047 | 7 | True | 1 | 4004 |
| 2 | 4004 | 4 | True | 2 | 400 |
| 3 | 400 | 0 | False | 2 | 40 |
| 4 | 40 | 0 | False | 2 | 4 |
| 5 | 4 | 4 | True | 3 | 0 |

Kết quả `count = 3`. Kiểm tra: 3 không phải 4 cũng không phải 7. In "NO".

---

### Bài 5: Elephant (Mã bài: 617A)

**Nguồn dữ liệu:** Codeforces Round #340 (Div. 2).

#### Đề bài chi tiết

Một chú voi đang đứng ở vị trí 0 trên trục tọa độ. Nhà của chú ở vị trí  (). Mỗi bước đi, chú voi có thể di chuyển 1, 2, 3, 4 hoặc 5 đơn vị về phía trước. Hãy tìm số bước đi tối thiểu để chú voi đến được nhà.

#### Phân tích Sư phạm

Đây là bài toán tối ưu hóa đơn giản (Greedy - Tham lam). Để đi nhanh nhất, chú voi nên ưu tiên các bước dài nhất (bước 5). Dù có thể giải bằng công thức toán học `(x + 4) / 5`, việc giải bằng `while` giúp học sinh hiểu cơ chế của thuật toán tham lam: lặp đi lặp lại hành động tốt nhất có thể tại thời điểm hiện tại.

#### Chiến lược Giải quyết

1. **Khởi tạo:** `x` là khoảng cách. `steps = 0`.
2. **Điều kiện lặp:** `while (x > 0)`.
3. **Thân vòng lặp:**
* Ta luôn muốn trừ 5. Nhưng nếu , ta chỉ cần bước đúng bằng .
* Tuy nhiên, vì mục tiêu là "số bước tối thiểu", ta chỉ cần đếm số lần bước. Dù bước 1 hay 5 thì cũng là 1 bước.
* Cách cài đặt `while` ngây thơ nhưng đúng logic tham lam:
* `if (x >= 5)`: `x = x - 5`.
* `else if (x >= 4)`: `x = x - 4`.
* ...
* `steps = steps + 1`.


* *Tối ưu hóa logic trong while:* Thực tế, ta luôn có thể bước 5 cho đến khi còn ít hơn 5, bước cuối cùng sẽ phủ nốt quãng đường còn lại.



#### Bảng Mô phỏng

Giả sử .

| Bước lặp | Khoảng cách còn lại () | Bước đi tốt nhất |  mới | Tổng số bước |
| --- | --- | --- | --- | --- |
| 1 | 12 | 5 | 7 | 1 |
| 2 | 7 | 5 | 2 | 2 |
| 3 | 2 | 2 (hoặc 5 coi như vượt qua) | 0 | 3 |

#### Nhận định Chuyên sâu

Bài này dạy học sinh cách mô phỏng quá trình trừ dần. Mặc dù kém hiệu quả hơn công thức toán  về mặt thời gian thực thi với số cực lớn, nhưng với giới hạn của bài toán, cách dùng `while` là , hoàn toàn chấp nhận được và mang tính giáo dục cao về tư duy thuật toán.

---

### Bài 6: Tram (Mã bài: 116A)

**Nguồn dữ liệu:** Codeforces Beta Round #87 (Div. 2).

#### Đề bài chi tiết

Một tuyến tàu điện đi qua  trạm. Tại mỗi trạm, có một số hành khách xuống tàu () và một số hành khách lên tàu (). Tàu khởi hành rỗng. Hãy tính sức chứa tối thiểu cần thiết của tàu để không bao giờ xảy ra tình trạng số khách trên tàu vượt quá sức chứa.

#### Phân tích Sư phạm

Bài toán yêu cầu theo dõi trạng thái biến thiên theo thời gian và tìm giá trị cực đại (Global Maximum) trong suốt quá trình đó. Đây là ứng dụng thực tế của biến tích lũy (accumulator) và biến cập nhật cực trị.

#### Chiến lược Giải quyết

1. **Khởi tạo:**
* `n`: Số trạm.
* `current_passengers = 0`: Số khách hiện tại.
* `min_capacity = 0`: Sức chứa tối thiểu cần tìm (chính là lượng khách tối đa từng xuất hiện).
* `i = 0`: Biến đếm trạm (dùng để kiểm soát vòng lặp `while`).


2. **Điều kiện lặp:** `while (i < n)`.
3. **Thân vòng lặp:**
* Đọc cặp số `a` (xuống), `b` (lên).
* Cập nhật số khách: `current_passengers = current_passengers - a + b`.
* Cập nhật cực đại: `if (current_passengers > min_capacity)` thì `min_capacity = current_passengers`.
* Tăng biến đếm: `i = i + 1`.


4. **Kết quả:** In `min_capacity`.

#### Bảng Mô phỏng

Input: 4 trạm. (0, 3), (2, 5), (4, 2), (4, 0).

| Trạm () | Xuống () | Lên () | Khách hiện tại () | Max () |
| --- | --- | --- | --- | --- |
| 0 | 0 | 3 |  | 3 |
| 1 | 2 | 5 |  | 6 (Cập nhật từ 3) |
| 2 | 4 | 2 |  | 6 (Không đổi) |
| 3 | 4 | 0 |  | 6 (Không đổi) |

**Kết quả:** 6.

---

## 4. Nhóm Bài tập Duyệt Mảng và Chuỗi (Array & String Traversal)

Đây là nhóm bài tập khó khăn nhất khi chuyển từ `for` sang `while` vì học sinh phải tự quản lý chỉ số (index). Rủi ro lớn nhất là quên tăng chỉ số (`i++`), dẫn đến lặp vô hạn (Time Limit Exceeded).

### Bài 7: Team (Mã bài: 231A)

**Nguồn dữ liệu:** Codeforces Round #143 (Div. 2).

#### Đề bài chi tiết

Có  bài toán trong cuộc thi. Ba người bạn Petya, Vasya và Tonya quyết định sẽ giải một bài toán nếu có ít nhất 2 người trong số họ chắc chắn về lời giải. Dữ liệu vào gồm  dòng, mỗi dòng chứa 3 số (0 hoặc 1) thể hiện ý kiến của từng người. Đếm số bài toán họ sẽ giải.

#### Phân tích Sư phạm

Bài toán này giới thiệu về duyệt mảng đầu vào (input stream) và logic boolean đơn giản.

#### Chiến lược Giải quyết

1. **Khởi tạo:** `n` (số bài), `solved_count = 0`, `i = 0`.
2. **Điều kiện lặp:** `while (i < n)`.
3. **Thân vòng lặp:**
* Đọc 3 biến `p, v, t` (đại diện cho Petya, Vasya, Tonya).
* Kiểm tra điều kiện: `if (p + v + t >= 2)`. Đây là cách ngắn gọn để kiểm tra "ít nhất 2 người", thay vì viết quá nhiều `if-else` lồng nhau.
* Nếu đúng: `solved_count = solved_count + 1`.
* **Quan trọng:** `i = i + 1`.


4. **Kết quả:** In `solved_count`.

---

### Bài 8: Next Round (Mã bài: 158A)

**Nguồn dữ liệu:** VK Cup 2012 Qualification Round 1.

#### Đề bài chi tiết

"Next Round" là bài toán lọc dữ liệu. Có  người tham gia với điểm số  (dữ liệu đảm bảo dãy không tăng, tức là ). Người tham gia sẽ được vào vòng sau nếu:

1. Điểm số dương ().
2. Điểm số lớn hơn hoặc bằng điểm của người xếp thứ  ().
Hãy đếm số người vào vòng sau.

#### Phân tích Sư phạm

Bài toán này yêu cầu truy cập mảng hai lần (hoặc lưu mảng). Lần 1 để lấy giá trị mốc (điểm của người thứ ), lần 2 để đếm. Tuy nhiên, vì dãy đã sắp xếp, ta có thể tối ưu. Nhưng với học sinh mới, cách an toàn là dùng mảng.

#### Chiến lược Giải quyết với `while`

1. **Lưu trữ:** Cần một mảng `scores` (vì , khai báo 100 cho an toàn).
2. **Vòng lặp 1 (Đọc dữ liệu):**
* `i = 0`. `while (i < n)`: `cin >> scores[i]`; `i++`.


3. **Xác định ngưỡng:**
* `cutoff_score = scores[k-1]`. (Lưu ý: đề bài dùng chỉ số 1-based, mảng C++ dùng 0-based nên phải là `k-1`).


4. **Vòng lặp 2 (Đếm):**
* `count = 0`, `i = 0`.
* `while (i < n)`:
* `if (scores[i] >= cutoff_score && scores[i] > 0)`: `count++`.
* `i++`.




5. **Kết quả:** In `count`.

#### Cạm bẫy

Học sinh thường quên điều kiện `scores[i] > 0`. Nếu điểm người thứ  là 0, những người có điểm 0 cũng không được vào vòng trong, dù điểm họ bằng người thứ .

---

### Bài 9: Soldier and Bananas (Mã bài: 546A)

**Nguồn dữ liệu:** Codeforces Round #304 (Div. 2).

#### Đề bài chi tiết

Một người lính muốn mua  quả chuối. Quả chuối đầu tiên giá , quả thứ hai giá ,..., quả thứ  giá . Anh ta có  đô la. Hỏi anh ta phải vay bao nhiêu tiền để trả đủ? (Nếu không phải vay, in 0).

#### Phân tích Sư phạm

Đây là bài toán tính tổng cấp số cộng. Học sinh có thể dùng công thức . Tuy nhiên, để luyện `while`, ta yêu cầu học sinh tính tổng bằng vòng lặp.

#### Chiến lược Giải quyết

1. **Khởi tạo:** `k, n, w`. `total_cost = 0`. `i = 1` (bắt đầu từ quả thứ 1).
2. **Điều kiện lặp:** `while (i <= w)`.
3. **Thân vòng lặp:**
* Giá của quả thứ `i` là `i * k`.
* Cộng dồn: `total_cost = total_cost + (i * k)`.
* `i = i + 1`.


4. **Xử lý kết quả:**
* Nếu `total_cost > n`: `borrow = total_cost - n`.
* Ngược lại: `borrow = 0`.



---

### Bài 10: Word (Mã bài: 59A)

**Nguồn dữ liệu:** Codeforces Beta Round #55 (Div. 2).

#### Đề bài chi tiết

Cho một từ chứa cả chữ hoa và chữ thường. Nhiệm vụ là chuẩn hóa từ đó:

* Nếu số lượng chữ hoa nhiều hơn chữ thường: Chuyển tất cả về chữ hoa.
* Ngược lại (chữ thường  chữ hoa): Chuyển tất cả về chữ thường.

#### Chiến lược Giải quyết

Bài toán yêu cầu 2 bước duyệt:

1. **Đếm:** Duyệt chuỗi bằng `while` để đếm `upper_cnt` và `lower_cnt`.
2. **Chuyển đổi:** So sánh hai biến đếm, sau đó duyệt lại chuỗi bằng một vòng `while` khác (hoặc reset biến chỉ số) để in ra hoặc sửa đổi chuỗi.

**Code Logic mô phỏng:**cpp
// Bước 1: Đếm
i = 0; upper = 0; lower = 0;
while (i < s.length()) {
if (s[i] >= 'A' && s[i] <= 'Z') upper++;
else lower++;
i++;
}
// Bước 2: Chuyển đổi
i = 0; // Reset chỉ số
while (i < s.length()) {
if (upper > lower) {
// Chuyển s[i] thành hoa
if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
} else {
// Chuyển s[i] thành thường
if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
}
cout << s[i];
i++;
}


---

### Bài 11: Translation (Mã bài: 41A)
**Nguồn dữ liệu:** Codeforces Beta Round #40 (Div. 2).[9]

#### Đề bài chi tiết
Cho hai chuỗi $s$ và $t$. Hãy kiểm tra xem chuỗi $t$ có phải là đảo ngược của chuỗi $s$ hay không. Ví dụ: "code" và "edoc" là đúng; "aba" và "aba" là đúng; "code" và "test" là sai.

#### Phân tích Sư phạm
Bài toán so sánh chuỗi với chỉ số chạy ngược nhau. Đây là bài tập tuyệt vời để hiểu về sự linh hoạt của chỉ số mảng (index manipulation).

#### Chiến lược Giải quyết
1.  **Kiểm tra sơ bộ:** Nếu độ dài `s` khác độ dài `t`, in "NO" ngay lập tức.
2.  **Khởi tạo:**
    *   `i = 0` (chỉ số đầu của s).
    *   `j = s.length() - 1` (chỉ số cuối của t).
    *   `match = true` (giả sử là đúng).
3.  **Điều kiện lặp:** `while (i < s.length())`.
4.  **Thân vòng lặp:**
    *   So sánh: `if (s[i]!= t[j])`. Nếu khác nhau $\rightarrow$ `match = false`. Có thể dừng vòng lặp ngay để tối ưu, nhưng nếu chỉ dùng `while` cơ bản thì cứ để chạy hết và dùng cờ `match` để ghi nhận lỗi.
    *   Cập nhật chỉ số: `i = i + 1`, `j = j - 1`. (Một cái tăng, một cái giảm).
5.  **Kết quả:** Dựa vào `match`.

---

### Bài 12: Way Too Long Words (Mã bài: 71A)
**Nguồn dữ liệu:** Codeforces Beta Round #65 (Div. 2).[3, 8]

#### Đề bài chi tiết
Một từ được gọi là "quá dài" nếu độ dài của nó lớn hơn 10 ký tự. Những từ quá dài cần được viết tắt: Chữ cái đầu + Số lượng ký tự ở giữa + Chữ cái cuối. Ví dụ: "localization" (12 ký tự) $\rightarrow$ "l10n". "internationalization" $\rightarrow$ "i18n".

#### Phân tích Sư phạm
Bài toán xử lý nhiều test case (trường hợp thử nghiệm). Đây là cấu trúc điển hình trong lập trình thi đấu: số đầu tiên $n$ là số lượng test case, theo sau là $n$ dòng dữ liệu.

#### Chiến lược Giải quyết
1.  **Khởi tạo:** Đọc `n`. `k = 0`.
2.  **Vòng lặp Test case:** `while (k < n)`.
3.  **Thân vòng lặp:**
    *   Đọc chuỗi `s`.
    *   Lấy độ dài `len = s.length()`.
    *   `if (len > 10)`: In `s`, in `len - 2`, in `s[len-1]`.
    *   `else`: In `s` nguyên bản.
    *   Xuống dòng.
    *   `k = k + 1`.

---

### Bài 13: Anton and Danik (Mã bài: 734A)
**Nguồn dữ liệu:** Codeforces Round #379 (Div. 2).[3, 5, 10]

#### Đề bài chi tiết
Anton và Danik chơi $n$ ván cờ. Chuỗi đầu vào ghi lại kết quả các ván đấu ('A' là Anton thắng, 'D' là Danik thắng). Hãy xác định ai thắng nhiều ván hơn hay là hòa (Friendship).

#### Chiến lược Giải quyết
Tương tự bài "Word" (59A), ta dùng `while` duyệt chuỗi và đếm.
1.  **Khởi tạo:** `anton = 0`, `danik = 0`, `i = 0`.
2.  **Lặp:** `while (i < n)`:
    *   `if (s[i] == 'A')`: `anton++`.
    *   `else`: `danik++`.
    *   `i++`.
3.  **So sánh:** Dùng chuỗi `if-else if-else` để in kết quả tương ứng.

---

## 5. Nhóm Bài tập Về Cờ Hiệu và Logic Nhị phân (Flags & Boolean Logic)

Nhóm bài tập này dạy học sinh cách sử dụng biến "cờ" (flag) để đánh dấu trạng thái. Một khi cờ đã bật lên, nó thường giữ nguyên trạng thái đó (hoặc ngược lại).

### Bài 14: In Search of an Easy Problem (Mã bài: 1030A)
**Nguồn dữ liệu:** TechnoCup 2019 Elimination Round 1.[11, 12, 13]

#### Đề bài chi tiết
Người tổ chức cuộc thi phỏng vấn $n$ người để xem bài toán có khó không. Nếu chỉ cần 1 người trả lời là "KHÓ" (giá trị 1), bài toán đó được coi là KHÓ (HARD). Nếu tất cả mọi người trả lời là "DỄ" (giá trị 0), bài toán mới được coi là DỄ (EASY).

#### Phân tích Sư phạm
Đây là bài toán tìm kiếm sự tồn tại (Existence Query). "Có tồn tại ít nhất một số 1 không?".

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `is_hard = 0` (Mặc định là dễ - False). `i = 0`.
2.  **Lặp:** `while (i < n)`:
    *   Đọc ý kiến `opinion`.
    *   `if (opinion == 1)`: `is_hard = 1`. (Tìm thấy bằng chứng là khó).
    *   `i++`.
3.  **Kết quả:** `if (is_hard == 1)` in "HARD", `else` in "EASY".
*   *Lưu ý:* Kể cả khi tìm thấy 1, nếu chưa học lệnh `break`, vòng lặp `while` vẫn sẽ chạy hết $n$ lần. Điều này không sai về kết quả, chỉ hơi kém về hiệu năng (nhưng với $n$ nhỏ thì không đáng kể).

---

### Bài 15: George and Accommodation (Mã bài: 467A)
**Nguồn dữ liệu:** Codeforces Round #267 (Div. 2).[9]

#### Đề bài chi tiết
George và Alex muốn chuyển vào ký túc xá. Có $n$ phòng. Phòng thứ $i$ hiện đang có $p_i$ người ở và có sức chứa tối đa $q_i$ người. Họ chỉ quyết định chuyển vào một phòng nếu phòng đó còn trống chỗ cho **cả hai** người (tức là sức chứa còn lại $\ge 2$). Đếm số phòng thỏa mãn.

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `n`. `count = 0`. `i = 0`.
2.  **Lặp:** `while (i < n)`:
    *   Đọc `p`, `q`.
    *   Khoảng trống: `space = q - p`.
    *   `if (space >= 2)`: `count = count + 1`.
    *   `i++`.
3.  **Kết quả:** In `count`.

---

## 6. Nhóm Bài tập Tư duy Không gian và Quy luật Toán học

Nhóm bài này yêu cầu học sinh hình dung vấn đề dưới dạng không gian (lưới 2D, hàng dọc) hoặc phát hiện quy luật (pattern).

### Bài 16: Beautiful Matrix (Mã bài: 263A)
**Nguồn dữ liệu:** Codeforces Round #161 (Div. 2).[3, 14, 15]

#### Đề bài chi tiết
Cho một ma trận 5x5. Có đúng một ô chứa số 1, các ô còn lại chứa số 0. Một bước di chuyển hợp lệ là đổi chỗ hai hàng liền kề hoặc hai cột liền kề. Hãy tìm số bước tối thiểu để đưa số 1 về tâm ma trận (vị trí hàng 3, cột 3).

#### Phân tích Sư phạm
Đây là bài toán về khoảng cách Manhattan trên lưới. Tâm ma trận 5x5 có tọa độ (3,3) (hoặc (2,2) nếu tính từ 0). Khoảng cách là $|row - 3| + |col - 3|$. Thách thức với học sinh dùng `while` là đọc ma trận 2 chiều.

#### Chiến lược Giải quyết
1.  **Đọc dữ liệu:** Ta không cần lưu cả ma trận, chỉ cần tìm tọa độ của số 1.
2.  **Vòng lặp lồng nhau (Nested While):**
    *   `row = 1`.
    *   `while (row <= 5)`:
        *   `col = 1`.
        *   `while (col <= 5)`:
            *   Đọc số `val`.
            *   `if (val == 1)`: Lưu lại `r_pos = row`, `c_pos = col`.
            *   `col++`.
        *   `row++`.
3.  **Tính toán:** Sử dụng hàm trị tuyệt đối `abs()` hoặc logic `if` để tính khoảng cách:
    *   `move_row = abs(r_pos - 3)`.
    *   `move_col = abs(c_pos - 3)`.
4.  **Kết quả:** `move_row + move_col`.

---

### Bài 17: Stones on the Table (Mã bài: 266A)
**Nguồn dữ liệu:** Codeforces Round #163 (Div. 2).[4]

#### Đề bài chi tiết
Có $n$ viên đá xếp thành hàng. Mỗi viên có màu Đỏ (R), Xanh lục (G), hoặc Xanh lam (B). Hãy tìm số lượng viên đá tối thiểu cần loại bỏ sao cho không có hai viên đá nào kề nhau có cùng màu.

#### Phân tích Sư phạm
Bài toán so sánh phần tử kề nhau ($i$ và $i+1$). Nếu giống nhau, ta phải loại bỏ một viên (về mặt logic đếm).

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `n`. Chuỗi `s`. `remove_count = 0`. `i = 0`.
2.  **Điều kiện lặp:** `while (i < n - 1)`. **Cực kỳ quan trọng:** Chỉ chạy đến $n-1$ vì ta sẽ truy cập `s[i+1]`. Nếu chạy đến $n$, `s[i+1]` sẽ truy cập ngoài mảng (Out of bounds).
3.  **Thân vòng lặp:**
    *   `if (s[i] == s[i+1])`: `remove_count++`.
    *   `i++`.
4.  **Kết quả:** In `remove_count`.

---

### Bài 18: Magnets (Mã bài: 344A)
**Nguồn dữ liệu:** Codeforces Round #200 (Div. 2).[16, 17, 18]

#### Đề bài chi tiết
Các thanh nam châm domino được xếp liền nhau. Mỗi thanh có cực "01" (dương-âm) hoặc "10" (âm-dương).
*   Nếu xếp "01" cạnh "10" $\rightarrow$ Khác cực $\rightarrow$ Hút nhau $\rightarrow$ Cùng nhóm.
*   Nếu xếp "01" cạnh "01" $\rightarrow$ Cùng cực $\rightarrow$ Đẩy nhau $\rightarrow$ Tách nhóm.
Đếm số lượng nhóm nam châm liên kết.

#### Phân tích Sư phạm
Bài toán "Phát hiện biên" (Edge detection). Mỗi khi giá trị thay đổi so với giá trị liền trước, một nhóm mới được hình thành.

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `n`. Đọc giá trị đầu tiên vào biến `prev`. `groups = 1` (ít nhất có 1 nhóm). `i = 1` (đã đọc 1 cái).
2.  **Lặp:** `while (i < n)`:
    *   Đọc giá trị hiện tại `curr`.
    *   `if (curr!= prev)`: `groups++`. (Có sự thay đổi $\rightarrow$ Ngắt quãng $\rightarrow$ Nhóm mới).
    *   Cập nhật: `prev = curr`. (Chuẩn bị cho bước sau).
    *   `i++`.

---

### Bài 19: Drinks (Mã bài: 200B)
**Nguồn dữ liệu:** Codeforces Round #126 (Div. 2).[19, 20, 21]

#### Đề bài chi tiết
Một ly cocktail được pha từ $n$ loại nước cam. Mỗi loại chiếm thể tích bằng nhau. Loại thứ $i$ có nồng độ nước cam nguyên chất là $p_i\%$. Tính nồng độ phần trăm nước cam trong ly cocktail hỗn hợp.

#### Phân tích Sư phạm
Về mặt toán học, đây là bài toán tính trung bình cộng. Về lập trình, đây là bài toán tính tổng và ép kiểu số thực (floating point).

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `n`. `sum = 0.0` (dùng double để tránh mất phần thập phân). `i = 0`.
2.  **Lặp:** `while (i < n)`:
    *   Đọc `p`.
    *   `sum = sum + p`.
    *   `i++`.
3.  **Kết quả:** In `sum / n`. Codeforces thường yêu cầu độ chính xác cao, nên dùng `fixed` và `setprecision`.

---

### Bài 20: Hulk (Mã bài: 705A)
**Nguồn dữ liệu:** Codeforces Round #366 (Div. 2).[22, 23]

#### Đề bài chi tiết
Tiến sĩ Bruce Banner diễn tả cảm xúc qua các lớp hành tây:
*   Lớp 1: "I hate"
*   Lớp 2: "I love"
*   Lớp 3: "I hate"
* ...
Các lớp nối với nhau bằng chữ "that". Kết thúc câu bằng "it".
Ví dụ $n=3$: "I hate that I love that I hate it".

#### Phân tích Sư phạm
Bài toán sinh mẫu (pattern generation) dựa trên tính chẵn lẻ của chỉ số.

#### Chiến lược Giải quyết
1.  **Khởi tạo:** `n`. `i = 1`.
2.  **Lặp:** `while (i <= n)`:
    *   `if (i % 2!= 0)`: In "I hate". (Lẻ là hate).
    *   `else`: In "I love". (Chẵn là love).
    *   **Xử lý nối từ:**
        *   `if (i == n)`: In " it". (Kết thúc).
        *   `else`: In " that ". (Còn nữa).
    *   `i++`.

---

## 7. Tổng kết và Lời khuyên Gỡ lỗi (Debugging Tips)

Khi làm việc với 20 bài tập trên chỉ bằng vòng lặp `while`, học sinh sẽ đối mặt với những thách thức đặc trưng. Dưới đây là bảng tổng hợp các lỗi thường gặp để giáo viên lưu ý:

| Loại lỗi | Biểu hiện | Nguyên nhân trong `while` | Cách khắc phục |
| :--- | :--- | :--- | :--- |
| **Lặp vô hạn (Infinite Loop)** | Chương trình chạy mãi không dừng, quá thời gian (TLE). | Quên cập nhật biến điều khiển (ví dụ: quên `i++` hoặc `n--`). | Luôn kiểm tra dòng cuối cùng của thân vòng lặp `while`. |
| **Lỗi biên (Off-by-one)** | Sai kết quả ở trường hợp biên, hoặc lỗi truy cập bộ nhớ. | Điều kiện `while (i < n)` hay `while (i <= n)`? | Vẽ bảng mô phỏng (Trace Table) cho trường hợp nhỏ ($n=1, n=2$). |
| **Biến rác (Uninitialized Var)** | Kết quả ra số ngẫu nhiên cực lớn/nhỏ. | Quên khởi tạo biến tổng (`sum = 0`) trước khi vào `while`. | Luôn gán giá trị ban đầu khi khai báo biến. |
| **Sai điều kiện dừng** | Vòng lặp dừng sớm hoặc muộn. | Nhầm lẫn giữa điều kiện "tiếp tục chạy" và điều kiện "dừng lại". | Đọc to điều kiện: "Trong khi [điều kiện] đúng, hãy làm...". |

Việc hoàn thành danh sách 20 bài tập này sẽ trang bị cho học sinh một nền tảng tư duy thuật toán vững chắc, hiểu rõ bản chất của việc điều khiển dòng dữ liệu, và sẵn sàng để tiếp thu các cấu trúc cao cấp hơn như `for` loops hay `recursion` (đệ quy) trong tương lai.

