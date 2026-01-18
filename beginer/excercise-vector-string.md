# Báo cáo Nghiên cứu Chuyên sâu: Phân tích Giải thuật và Cấu trúc Dữ liệu String/Vector trên Codeforces (Elo 800-1000)

## Tóm tắt Điều hành

Báo cáo này cung cấp một phân tích toàn diện và chuyên sâu về 20 bài tập lập trình thi đấu nền tảng trên nền tảng Codeforces, được chọn lọc kỹ lưỡng trong khoảng xếp hạng Elo từ 800 đến 1000. Mục tiêu chính của tài liệu này là trang bị cho các lập trình viên mới bắt đầu (Newbie/Pupil) kiến thức vững chắc về hai cấu trúc dữ liệu quan trọng nhất trong C++ Standard Template Library (STL): `std::string` (chuỗi ký tự) và `std::vector` (mảng động).

Không chỉ dừng lại ở việc cung cấp lời giải, báo cáo đi sâu vào phân tích lý thuyết đằng sau mỗi bài toán, bao gồm độ phức tạp thuật toán (Time/Space Complexity), quản lý bộ nhớ, và các kỹ thuật tư duy tham lam (Greedy) hoặc mô phỏng (Simulation). Mỗi bài tập đi kèm với một bản dịch tiếng Việt chính xác, liên kết trực tiếp đến đề bài gốc, và một phần phân tích chiến lược giải quyết vấn đề chi tiết, đóng vai trò như một giáo trình thu nhỏ cho việc tự học khoa học máy tính.

---

## Phần I: Cơ sở Lý thuyết và Tổng quan Danh sách Bài tập

Giai đoạn đánh giá Elo 800-1000 trên Codeforces được coi là giai đoạn "sàng lọc". Tại đây, các bài toán không đòi hỏi các thuật toán phức tạp như Quy hoạch động (Dynamic Programming) hay Đồ thị nâng cao (Graph Theory), mà tập trung kiểm tra khả năng chuyển đổi ý tưởng logic thành mã nguồn sạch, tối ưu và chính xác. Sự thành thạo trong việc thao tác chuỗi và vector ở giai đoạn này là tiền đề bắt buộc để tiến lên các bậc xếp hạng cao hơn như Specialist hay Expert.[1, 2]

Dưới đây là bảng tổng hợp các bài tập được phân tích trong báo cáo này, được sắp xếp theo chủ đề kỹ thuật:

| STT | Tên Bài Toán (ID) | Chủ đề Chính | Cấu trúc Dữ liệu | Độ khó (Elo) |
|:---:|:---|:---|:---|:---:|
| 1 | Way Too Long Words (71A) | Xử lý độ dài chuỗi | String | 800 |
| 2 | Word (59A) | Phân loại ký tự (Case) | String | 800 |
| 3 | Word Capitalization (281A) | Truy cập chỉ số mảng | String | 800 |
| 4 | Translation (41A) | Đảo ngược chuỗi | String | 800 |
| 5 | Petya and Strings (112A) | So sánh từ điển | String | 800 |
| 6 | Amusing Joke (141A) | Sắp xếp & Tần suất | String/Vector | 800 |
| 7 | Pangram (520A) | Tập hợp (Set) | String | 800 |
| 8 | Boy or Girl (236A) | Đếm phần tử duy nhất | String/Set | 800 |
| 9 | Stones on the Table (266A) | Quét tuyến tính | String | 800 |
| 10 | Anton and Danik (734A) | Biến đếm tích lũy | String | 800 |
| 11 | Queue at the School (266B) | Mô phỏng theo thời gian | String | 800 |
| 12 | Chat Room (58A) | Tìm chuỗi con (Subsequence) | String | 1000 |
| 13 | Dubstep (208A) | Phân tách (Tokenization) | String | 900 |
| 14 | String Task (118A) | Lọc & Biến đổi | String | 1000 |
| 15 | Twins (160A) | Thuật toán tham lam | Vector | 900 |
| 16 | Arrival of the General (144A)| Tìm cực trị (Min/Max) | Vector | 800 |
| 17 | Helpful Maths (339A) | Parsing & Sắp xếp | String/Vector | 800 |
| 18 | Magnets (344A) | Phát hiện chuyển đổi | Vector | 800 |
| 19 | Tram (116A) | Tổng tiền tố (Prefix Sum) | Vector | 800 |
| 20 | Ultra-Fast Mathematician (61A)| Toán tử Bitwise | String | 800 |

---

## Phần II: Phân tích Chi tiết Từng Bài Toán

### 1. Way Too Long Words (Mã bài: 71A)
**Liên kết:** [Codeforces 71A](https://codeforces.com/problemset/problem/71/A)
**Nguồn tham khảo:** [3, 4, 5, 6]

#### Bản dịch Đề bài (Tiếng Việt)
Đôi khi, các từ như "localization" (bản địa hóa) hay "internationalization" (quốc tế hóa) quá dài khiến việc viết đi viết lại chúng trong văn bản trở nên mệt mỏi. Hãy coi một từ là "quá dài" nếu độ dài của nó thực sự lớn hơn 10 ký tự.

Tất cả các từ quá dài cần được thay thế bằng một từ viết tắt đặc biệt. Quy tắc viết tắt như sau: Ta viết ký tự đầu tiên và ký tự cuối cùng của từ, và ở giữa hai ký tự đó, ta viết số lượng các ký tự nằm giữa chúng. Số này được viết ở hệ thập phân và không có số 0 ở đầu.

Ví dụ, "localization" sẽ được viết tắt thành "l10n", và "internationalization" sẽ thành "i18n".
Nhiệm vụ của bạn là tự động hóa quy trình này. Nếu một từ không quá dài, hãy giữ nguyên nó.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán này là bài kiểm tra cơ bản nhất về khả năng **truy cập ngẫu nhiên (random access)** trên chuỗi và **điều kiện rẽ nhánh**.
Trong C++, `std::string` hoạt động như một mảng động các ký tự. Điểm mấu chốt ở đây là tư duy về chỉ số (index):
*   Ký tự đầu tiên luôn nằm ở chỉ số `0`.
*   Ký tự cuối cùng nằm ở chỉ số `n - 1`, với `n` là độ dài chuỗi.
*   Số lượng ký tự nằm giữa đầu và cuối chính là tổng độ dài trừ đi 2 (đầu và cuối).

**Cạm bẫy tiềm ẩn:**
Nhiều người mới bắt đầu thường nhầm lẫn điều kiện `> 10`. Đề bài ghi rõ "strictly more than 10 characters" (thực sự lớn hơn 10). Tức là một từ có đúng 10 ký tự sẽ không được viết tắt. Việc xử lý sai toán tử so sánh (`>=` thay vì `>`) là lỗi phổ biến nhất.[4]

**Giải pháp Tối ưu:**
1.  Đọc số nguyên `n` (số lượng từ).
2.  Sử dụng vòng lặp `while(n--)` để xử lý từng từ.
3.  Với mỗi từ `s`, kiểm tra `s.length()`.
4.  Nếu `s.length() > 10`: In ra `s` + `(s.length() - 2)` + `s.back()`.
5.  Ngược lại: In ra `s` nguyên bản.
Độ phức tạp thời gian là $O(1)$ cho mỗi từ (vì độ dài từ bị giới hạn nhỏ trong việc in ấn) hoặc chính xác là $O(L)$ với $L$ là độ dài từ.

---

### 2. Word (Mã bài: 59A)
**Liên kết:** [Codeforces 59A](https://codeforces.com/problemset/problem/59/A)
**Nguồn tham khảo:** [7, 8]

#### Bản dịch Đề bài (Tiếng Việt)
Vasya rất khó chịu khi nhìn thấy các từ mà chữ hoa và chữ thường lẫn lộn, ví dụ như "HoUse". Anh ấy quyết định thay thế tất cả các ký tự trong từ đó sao cho từ chỉ còn chứa toàn chữ thường hoặc toàn chữ hoa.

Quy tắc: Hãy thay đổi ít ký tự nhất có thể.
*   Nếu số lượng chữ hoa nhiều hơn số lượng chữ thường: Chuyển toàn bộ từ thành chữ hoa.
*   Trường hợp khác (số chữ hoa ít hơn hoặc bằng số chữ thường): Chuyển toàn bộ từ thành chữ thường.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán yêu cầu kỹ năng **duyệt mảng (iteration)** và **thao tác mã ASCII**.
Trong bảng mã ASCII:
*   'A' đến 'Z' có giá trị từ 65 đến 90.
*   'a' đến 'z' có giá trị từ 97 đến 122.
Khoảng cách giữa chữ hoa và chữ thường tương ứng là 32 đơn vị. Tuy nhiên, thay vì cộng trừ thủ công, ta nên dùng thư viện `<cctype>` với các hàm `isupper()`, `tolower()`, `toupper()`.

**Chiến lược:**
Thuật toán cần thực hiện hai lần duyệt (2-pass algorithm) hoặc một lần duyệt với bộ nhớ đệm:
1.  **Bước Đếm:** Duyệt qua chuỗi để đếm số lượng ký tự hoa (`upper_count`) và thường (`lower_count`).
2.  **Bước Quyết định:** So sánh hai biến đếm.
3.  **Bước Biến đổi:** Duyệt lại chuỗi và dùng hàm `toupper` hoặc `tolower` để in ra kết quả. Việc này đảm bảo ta tuân thủ nguyên tắc "thay đổi ít nhất" mà đề bài yêu cầu một cách gián tiếp thông qua quy tắc số lượng.

---

### 3. Word Capitalization (Mã bài: 281A)
**Liên kết:** [Codeforces 281A](https://codeforces.com/problemset/problem/281/A)
**Nguồn tham khảo:** [7, 8]

#### Bản dịch Đề bài (Tiếng Việt)
Viết hoa (Capitalization) là việc viết ký tự đầu tiên của một từ thành chữ in hoa. Nhập vào một từ không rỗng chứa các chữ cái Latin in thường hoặc in hoa. Hãy thực hiện viết hoa từ đó.
Lưu ý: Nếu ký tự đầu tiên đã là chữ hoa, từ đó giữ nguyên không đổi.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Đây là bài tập cơ bản về **tính khả biến (mutability)** của chuỗi ký tự. Trong C++, toán tử `` trả về một tham chiếu (reference) đến ký tự tại vị trí đó, cho phép ta sửa đổi trực tiếp bộ nhớ.

**Kiến thức cốt lõi:**
Hàm `toupper(char c)` có tính chất **lũy đẳng (idempotent)** đối với các ký tự đã viết hoa hoặc không phải chữ cái. Tức là `toupper('A')` trả về 'A'. Do đó, ta không cần dùng câu lệnh điều kiện `if` để kiểm tra xem ký tự đầu có phải chữ thường hay không. Ta chỉ cần áp dụng `toupper` lên `s` một cách vô điều kiện. Điều này giúp mã nguồn ngắn gọn và nhanh hơn (tránh branch misprediction trong CPU).

---

### 4. Translation (Mã bài: 41A)
**Liên kết:** [Codeforces 41A](https://codeforces.com/problemset/problem/41/A)
**Nguồn tham khảo:** [8, 9]

#### Bản dịch Đề bài (Tiếng Việt)
Ngôn ngữ Berlandian và ngôn ngữ Birlandian rất giống nhau, điểm khác biệt duy nhất là các từ được viết ngược lại. Ví dụ, từ "code" trong tiếng Berlandian sẽ là "edoc" trong tiếng Birlandian.

Bạn được cung cấp một từ $s$ trong tiếng Berlandian và một từ $t$ trong tiếng Birlandian. Hãy kiểm tra xem từ $t$ có phải là bản dịch (viết ngược) của từ $s$ hay không.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán giới thiệu khái niệm **Đảo ngược chuỗi (String Reversal)**. Có hai hướng tiếp cận chính:
1.  **Tiếp cận Xây dựng (Constructive):** Tạo ra một bản sao của chuỗi $s$, đảo ngược bản sao đó bằng hàm `std::reverse(s.begin(), s.end())`, sau đó so sánh trực tiếp với $t$.
2.  **Tiếp cận Con trỏ kép (Two Pointers):** Đây là cách tối ưu hơn về bộ nhớ. Ta so sánh ký tự đầu của $s$ với ký tự cuối của $t$, ký tự thứ hai của $s$ với ký tự áp chót của $t$, v.v.
    *   Công thức: Kiểm tra `s[i] == t[len - 1 - i]` với mọi $i$ từ 0 đến `len-1`.
    *   Ngay khi tìm thấy một cặp không khớp, in "NO" và kết thúc. Nếu chạy hết vòng lặp, in "YES".

Lưu ý: Cần kiểm tra độ dài hai chuỗi trước. Nếu độ dài khác nhau, chắc chắn không phải là bản dịch của nhau.

---

### 5. Petya and Strings (Mã bài: 112A)
**Liên kết:** [Codeforces 112A](https://codeforces.com/problemset/problem/112/A)
**Nguồn tham khảo:** [4, 9]

#### Bản dịch Đề bài (Tiếng Việt)
Petya nhận được hai chuỗi ký tự có cùng độ dài. Cậu muốn so sánh chúng theo **thứ tự từ điển (lexicographical order)**. Tuy nhiên, Petya không quan tâm đến việc chữ cái là hoa hay thường (case-insensitive).
*   Nếu chuỗi thứ nhất nhỏ hơn chuỗi thứ hai: in "-1".
*   Nếu chuỗi thứ hai nhỏ hơn chuỗi thứ nhất: in "1".
*   Nếu hai chuỗi bằng nhau: in "0".

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Khái niệm "thứ tự từ điển" tương đương với cách xếp từ trong từ điển: so sánh từng ký tự từ trái sang phải. Ký tự nào có mã ASCII nhỏ hơn thì từ chứa nó được coi là nhỏ hơn.

**Vấn đề:** Mã ASCII của 'Z' (90) nhỏ hơn 'a' (97). Do đó, nếu so sánh trực tiếp, "Zebra" sẽ nhỏ hơn "apple", điều này sai về mặt ngữ nghĩa thông thường.
**Giải pháp:**
Cần **chuẩn hóa dữ liệu (Data Normalization)** trước khi so sánh.
1.  Duyệt qua cả hai chuỗi, chuyển toàn bộ về chữ thường (hoặc toàn bộ về chữ hoa).
2.  Sử dụng hàm so sánh chuỗi có sẵn trong C++ (`string::compare` hoặc các toán tử `<`, `>`).
    *   Trong C++, `str1 < str2` trả về true/false.
    *   Hàm `strcmp` trong C cũ trả về âm/dương/0, rất khớp với yêu cầu đề bài, nhưng yêu cầu chuyển đổi sang C-string (`.c_str()`).
    *   Cách thủ công (tốt cho việc học): Duyệt vòng lặp, tìm vị trí `i` đầu tiên mà `s1[i]!= s2[i]`. So sánh hai ký tự đó để quyết định kết quả 1 hay -1.

---

### 6. Amusing Joke (Mã bài: 141A)
**Liên kết:** [Codeforces 141A](https://codeforces.com/problemset/problem/141/A)
**Nguồn tham khảo:** [10, 11, 12]

#### Bản dịch Đề bài (Tiếng Việt)
Vào dịp năm mới, mọi người treo một bảng chữ cái hỗn loạn. Bảng này thực chất là tên của người khách (Guest) và tên của chủ nhà (Host) bị trộn lẫn vào nhau.
Bạn được cho 3 chuỗi: tên khách, tên chủ nhà, và chuỗi ký tự hỗn loạn kia. Hãy kiểm tra xem chuỗi hỗn loạn có phải được tạo thành chính xác từ các ký tự của tên khách và tên chủ nhà gộp lại hay không (không thừa, không thiếu ký tự nào).

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Đây là bài toán về **Bảo toàn Số lượng (Conservation of Count)** hay còn gọi là bài toán Anagram (đảo chữ). Thứ tự không quan trọng, chỉ có tần suất ký tự là quan trọng.

**Cách 1: Sắp xếp (Sorting - $O(N \log N)$)**
Đây là cách dễ cài đặt nhất.
1.  Tạo chuỗi tổng hợp: `S = Guest + Host`.
2.  Sắp xếp chuỗi `S` theo thứ tự alphabet: `sort(S.begin(), S.end())`.
3.  Sắp xếp chuỗi hỗn loạn `Pile`: `sort(Pile.begin(), Pile.end())`.
4.  So sánh: Nếu `S == Pile` thì in "YES", ngược lại in "NO".
Việc sắp xếp giúp biến một cấu trúc hỗn loạn thành một cấu trúc có thứ tự duy nhất (canonical form), giúp việc so sánh trở nên tầm thường.[10]

**Cách 2: Mảng đếm tần suất (Frequency Map - $O(N)$)**
Sử dụng mảng `int count[13]`. Duyệt qua tên khách và chủ nhà, tăng biến đếm tương ứng cho mỗi ký tự. Sau đó duyệt qua chuỗi hỗn loạn và giảm biến đếm. Cuối cùng, kiểm tra nếu toàn bộ mảng `count` đều bằng 0 thì đúng. Cách này tối ưu hơn về thời gian nhưng dài dòng hơn khi cài đặt.

---

### 7. Pangram (Mã bài: 520A)
**Liên kết:** [Codeforces 520A](https://codeforces.com/problemset/problem/520/A)
**Nguồn tham khảo:** [14, 15, 16]

#### Bản dịch Đề bài (Tiếng Việt)
Một chuỗi được gọi là Pangram nếu nó chứa đầy đủ tất cả các chữ cái trong bảng chữ cái Latin (từ A đến Z), không phân biệt hoa thường.
Cho số $n$ và một chuỗi $s$, hãy kiểm tra xem nó có phải là Pangram hay không.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán yêu cầu kiểm tra tính **bao phủ tập hợp**. Ta cần biết liệu tập hợp các ký tự xuất hiện trong chuỗi có kích thước bằng 26 hay không.

**Cấu trúc dữ liệu: `std::set` hoặc Mảng đánh dấu.**
1.  **Cách dùng `std::set`:** Set là cấu trúc dữ liệu lưu trữ các phần tử không trùng lặp.
    *   Duyệt qua chuỗi, chuyển ký tự về chữ thường và đưa vào set.
    *   Cuối cùng kiểm tra `mySet.size() == 26`.
2.  **Cách dùng Mảng đánh dấu (Boolean Array):**
    *   Khởi tạo `bool visited[13] = {false}`.
    *   Duyệt chuỗi: `visited[tolower(s[i]) - 'a'] = true;`.
    *   Duyệt mảng `visited`, nếu tìm thấy bất kỳ giá trị `false` nào -> In "NO". Nếu không -> In "YES".

**Góc nhìn chuyên gia:** Nếu $n < 26$, ta có thể in "NO" ngay lập tức vì không thể nào đủ 26 chữ cái. Đây là một tối ưu hóa nhỏ (early exit).[15]

---

### 8. Boy or Girl (Mã bài: 236A)
**Liên kết:** [Codeforces 236A](https://codeforces.com/problemset/problem/236/A)
**Nguồn tham khảo:** [7, 8]

#### Bản dịch Đề bài (Tiếng Việt)
Có một phương pháp (vui) để xác định giới tính của người dùng dựa trên tên của họ (username).
*   Nếu số lượng **ký tự phân biệt** (distinct characters) trong tên là số LẺ: Đó là NAM -> in "IGNORE HIM!".
*   Nếu số lượng **ký tự phân biệt** là số CHẴN: Đó là NỮ -> in "CHAT WITH HER!".

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán này tương tự như bài Pangram, tập trung vào việc đếm số lượng phần tử duy nhất (Cardinality of a Set).
Các bước thực hiện:
1.  Dùng `std::sort(s.begin(), s.end())` để gom các ký tự giống nhau lại gần nhau.
2.  Sử dụng hàm `std::unique(s.begin(), s.end())` để loại bỏ các ký tự trùng lặp liền kề (lưu ý: hàm này không thực sự xóa phần tử mà chỉ đẩy chúng về cuối, trả về iterator mới).
3.  Hoặc đơn giản hơn: Dùng `std::set<char> mySet`. Chèn tất cả ký tự vào Set.
4.  Lấy kích thước `mySet.size()`.
5.  Kiểm tra tính chẵn lẻ: `size % 2 == 0` -> NỮ, ngược lại -> NAM.

---

### 9. Stones on the Table (Mã bài: 266A)
**Liên kết:** [Codeforces 266A](https://codeforces.com/problemset/problem/266/A)
**Nguồn tham khảo:** [9, 17, 18]

#### Bản dịch Đề bài (Tiếng Việt)
Có $n$ viên đá xếp thành hàng trên bàn. Mỗi viên có màu Đỏ (R), Xanh lá (G), hoặc Xanh dương (B).
Hãy đếm số lượng tối thiểu các viên đá cần lấy ra khỏi bàn sao cho **không có hai viên đá nào nằm cạnh nhau có cùng màu**.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Đây là dạng bài toán **Tham lam (Greedy)** đơn giản nhất trên cấu trúc tuyến tính.
Mục tiêu là phá vỡ mọi cặp `(i, i+1)` mà `s[i] == s[i+1]`.
Khi ta gặp hai viên đá giống nhau cạnh nhau (ví dụ: RR), ta bắt buộc phải loại bỏ một trong hai. Việc loại bỏ viên nào trong hai viên đó không ảnh hưởng đến các cặp phía sau một cách khác biệt (về mặt logic toán học cho bài này), nên ta chỉ cần đếm số lần trùng lặp.

**Thuật toán:**
Duyệt từ đầu đến sát cuối chuỗi (`0` đến `n-2`).
Nếu `s[i] == s[i+1]`: Tăng biến đếm `count`.
Kết quả chính là `count`.
Độ phức tạp: $O(N)$ thời gian, $O(1)$ bộ nhớ phụ.

---

### 10. Anton and Danik (Mã bài: 734A)
**Liên kết:** [Codeforces 734A](https://codeforces.com/contest/734/problem/A)
**Nguồn tham khảo:** [19, 20]

#### Bản dịch Đề bài (Tiếng Việt)
Anton và Danik chơi n ván cờ vua. Kết quả được ghi lại là một chuỗi ký tự, 'A' là Anton thắng, 'D' là Danik thắng.
Hãy xác định ai thắng nhiều hơn.
*   Anton nhiều hơn -> In "Anton".
*   Danik nhiều hơn -> In "Danik".
*   Bằng nhau -> In "Friendship".

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán **Tổng hợp dữ liệu (Aggregation)** cơ bản.
Không cần mảng hay cấu trúc phức tạp. Ta chỉ cần hai biến nguyên `int a_wins = 0, d_wins = 0`.
Duyệt chuỗi một lần duy nhất. Gặp 'A' tăng `a_wins`, gặp 'D' tăng `d_wins`.
Cuối cùng dùng chuỗi lệnh `if - else if - else` để in kết quả. Đây là bài tập tốt để làm quen với luồng điều khiển cơ bản.

---

### 11. Queue at the School (Mã bài: 266B)
**Liên kết:**(([https://codeforces.com/problemset/problem/266/B](https://codeforces.com/problemset/problem/266/B)))
**Nguồn tham khảo:** [21, 22]

#### Bản dịch Đề bài (Tiếng Việt)
Học sinh xếp hàng trong căng tin. Hàng đợi được mô tả bằng chuỗi chứa 'B' (Boy - Nam) và 'G' (Girl - Nữ).
Quy tắc: Nếu một cậu bé đứng ngay trước một cô bé, họ sẽ đổi chỗ cho nhau vì phép lịch sự. Quá trình này xảy ra **đồng thời** ở mọi vị trí trong mỗi giây.
Cho trạng thái ban đầu và thời gian $t$, hãy in ra trạng thái hàng đợi sau $t$ giây.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Đây là bài toán **Mô phỏng (Simulation)**.
Điểm khó nhất ở đây là chữ "đồng thời". Nếu ta duyệt từ trái sang phải và hoán đổi liên tục trong một vòng lặp đơn, một cậu bé 'B' có thể bị đẩy từ đầu hàng xuống cuối hàng chỉ trong 1 giây (hiệu ứng dồn toa), điều này sai so với đề bài.

**Giải pháp đúng:**
Cần tách biệt các bước thời gian.
1.  Vòng lặp ngoài chạy $t$ lần (đếm thời gian).
2.  Vòng lặp trong duyệt từ đầu đến sát cuối hàng.
3.  Kiểm tra: Nếu `s[i] == 'B'` VÀ `s[i+1] == 'G'`:
    *   Hoán đổi (`swap(s[i], s[i+1])`).
    *   **Quan trọng:** Tăng chỉ số `i` thêm 1 đơn vị nữa (`i++`) để nhảy qua vị trí vừa hoán đổi. Nếu không nhảy qua, ở vòng lặp tiếp theo của `i`, ta lại gặp chính cậu bé đó (giờ đang ở vị trí mới) và lại đổi chỗ tiếp, dẫn đến lỗi "dồn toa" đã nói ở trên.

---

### 12. Chat Room (Mã bài: 58A)
**Liên kết:** [Codeforces 58A](https://codeforces.com/problemset/problem/58/A)
**Nguồn tham khảo:** [23, 24, 25]

#### Bản dịch Đề bài (Tiếng Việt)
Vasya muốn gõ chữ "hello". Vì gõ vội, anh ta có thể gõ thêm các ký tự thừa hoặc lặp lại ký tự. Ví dụ "ahhellllloou".
Hãy kiểm tra xem Vasya có thực sự nói "hello" không. Điều này đúng nếu ta có thể xóa đi một số ký tự trong chuỗi đã gõ để thu được "hello" (tức là "hello" là một **chuỗi con - subsequence** của chuỗi đã gõ).

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán kiểm tra khái niệm **Subsequence Matching**.
Ta có thể mô hình hóa bài toán bằng một **Máy trạng thái hữu hạn (Finite State Machine)** đơn giản.
Mục tiêu: `target = "hello"`.
Biến trỏ `j` chỉ vào ký tự đang cần tìm trong `target` (ban đầu `j=0`, cần tìm 'h').
Duyệt qua chuỗi nhập vào `s`:
*   Nếu `s[i] == target[j]`: Ta đã tìm thấy ký tự cần thiết, tăng `j` lên 1 để tìm ký tự tiếp theo.
*   Nếu `j` đạt đến 5 (độ dài của "hello"): In "YES" và kết thúc chương trình.
Nếu duyệt hết chuỗi mà `j < 5`: In "NO".

Chiến thuật tham lam (Greedy) được áp dụng ở đây: Ta luôn chọn ký tự phù hợp *đầu tiên* mà ta thấy, vì việc bỏ qua nó để chờ một ký tự giống hệt phía sau không mang lại lợi ích gì (thậm chí còn làm giảm không gian tìm kiếm cho các ký tự còn lại).[23]

---

### 13. Dubstep (Mã bài: 208A)
**Liên kết:** [Codeforces 208A](https://codeforces.com/problemset/problem/208/A)
**Nguồn tham khảo:** [26, 13, 27]

#### Bản dịch Đề bài (Tiếng Việt)
Vasya remix một bài hát bằng cách chèn từ "WUB" vào trước, sau, hoặc giữa các từ của bài hát gốc. Ví dụ: "I AM X" -> "WUBWUBIWUBAMWUBWUBX".
Hãy khôi phục bài hát gốc. Các từ trong kết quả phải cách nhau bởi 1 dấu cách (không có dấu cách thừa ở đầu/cuối).

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Đây là bài toán **Phân tích cú pháp (Parsing/Tokenization)**.
"WUB" đóng vai trò là dấu phân cách (delimiter). Khó khăn nằm ở việc xử lý nhiều dấu phân cách liên tiếp ("WUBWUB") và việc in dấu cách đúng vị trí (chỉ in giữa các từ, không in ở đầu dòng).

**Thuật toán:**
1.  Duyệt chuỗi. Kiểm tra xem 3 ký tự tiếp theo có phải là "WUB" không.
2.  Nếu là "WUB": Nhảy qua 3 ký tự (`i += 3`). Đánh dấu một cờ hiệu (flag) là `needs_space = true`.
3.  Nếu không phải "WUB":
    *   Kiểm tra cờ `needs_space`. Nếu `true` và đây không phải từ đầu tiên -> in ra " ".
    *   In ký tự hiện tại.
    *   Đặt `needs_space = false`.

---

### 14. String Task (Mã bài: 118A)
**Liên kết:** [Codeforces 118A](https://codeforces.com/problemset/problem/118/A)
**Nguồn tham khảo:** [8, 28]

#### Bản dịch Đề bài (Tiếng Việt)
Xử lý một chuỗi theo quy tắc:
1.  Xóa tất cả các nguyên âm: 'A', 'O', 'Y', 'E', 'U', 'I' (Lưu ý: Y được tính là nguyên âm trong bài này).
2.  Chèn dấu chấm "." trước mỗi phụ âm.
3.  Chuyển tất cả chữ hoa thành chữ thường.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán kết hợp **Lọc (Filtering)** và **Chuyển dạng (Transformation)**.
Thay vì cố gắng sửa đổi chuỗi tại chỗ (in-place modification) vốn rất phức tạp và tốn kém ($O(N^2)$ nếu dùng `erase` hoặc `insert` liên tục), ta nên tạo một chuỗi kết quả mới (StringBuilder pattern).

Duyệt từng ký tự `c`:
1.  Chuyển `c = tolower(c)`.
2.  Kiểm tra xem `c` có thuộc tập `{'a', 'o', 'y', 'e', 'u', 'i'}` không.
3.  Nếu không phải nguyên âm (tức là phụ âm): Thêm `.` vào kết quả, sau đó thêm `c`.
4.  Nếu là nguyên âm: Bỏ qua.

---

### 15. Twins (Mã bài: 160A)
**Liên kết:** [Codeforces 160A](https://codeforces.com/problemset/problem/160/A)
**Nguồn tham khảo:** [29, 30, 31]

#### Bản dịch Đề bài (Tiếng Việt)
Bạn có $n$ đồng xu với các giá trị khác nhau. Bạn muốn chia số tiền này cho bạn và em song sinh. Bạn muốn lấy số lượng đồng xu **ít nhất** sao cho tổng giá trị của chúng **lớn hơn hẳn** (> strictly greater) tổng giá trị các đồng xu còn lại của em.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán minh họa sức mạnh của **Thuật toán Tham lam (Greedy Algorithm)** kết hợp với **Sắp xếp (Sorting)**.
Để tối ưu hóa (lấy ít xu nhất mà được giá trị lớn nhất), chiến lược tốt nhất luôn là lấy đồng xu có mệnh giá cao nhất hiện có.

**Các bước:**
1.  Đọc các giá trị vào một `std::vector<int>`.
2.  Tính tổng toàn bộ (`total_sum`).
3.  Sắp xếp vector giảm dần (`std::sort(v.rbegin(), v.rend())`).
4.  Duyệt vector, lấy từng đồng xu vào `my_sum`.
5.  Dừng lại ngay khi `my_sum > total_sum / 2` (hoặc `my_sum > total_sum - my_sum`).
6.  Kết quả là số đồng xu đã lấy.
Độ phức tạp bị chi phối bởi thuật toán sắp xếp: $O(N \log N)$.

---

### 16. Arrival of the General (Mã bài: 144A)
**Liên kết:** [Codeforces 144A](https://codeforces.com/problemset/problem/144/A)
**Nguồn tham khảo:** [28, 32]

#### Bản dịch Đề bài (Tiếng Việt)
Một vị tướng muốn sắp xếp hàng lính sao cho người cao nhất đứng đầu hàng (chỉ số 0) và người thấp nhất đứng cuối hàng (chỉ số n-1).
Bạn chỉ được phép đổi chỗ hai người đứng cạnh nhau. Tính số lần đổi chỗ tối thiểu.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán tìm kiếm **Cực trị (Min/Max)** và tính toán **Khoảng cách Manhattan** trên mảng 1 chiều.
Số lần đổi chỗ để đưa một phần tử về vị trí đích chính là khoảng cách chỉ số giữa vị trí hiện tại và đích.
1.  Tìm chỉ số của người cao nhất (`max_idx`). Lưu ý: Nếu có nhiều người cao bằng nhau, chọn người đứng gần đầu hàng nhất (chỉ số nhỏ nhất) để tốn ít lần đổi chỗ nhất.
2.  Tìm chỉ số của người thấp nhất (`min_idx`). Lưu ý: Nếu có nhiều người thấp bằng nhau, chọn người đứng gần cuối hàng nhất (chỉ số lớn nhất).
3.  Công thức cơ bản: `max_idx` (số bước đưa max về 0) + `(n - 1 - min_idx)` (số bước đưa min về cuối).
4.  **Điều chỉnh giao nhau:** Nếu `max_idx > min_idx`, nghĩa là người cao nhất đang đứng sau người thấp nhất. Khi di chuyển người cao nhất lên đầu, ta sẽ hoán đổi với người thấp nhất 1 lần. Do đó, người thấp nhất bị đẩy lùi về phía sau 1 bước "miễn phí". Ta cần trừ đi 1 vào tổng kết quả.

---

### 17. Helpful Maths (Mã bài: 339A)
**Liên kết:** [Codeforces 339A](https://codeforces.com/problemset/problem/339/A)
**Nguồn tham khảo:** [9]

#### Bản dịch Đề bài (Tiếng Việt)
Xenia cần tính tổng các con số (chỉ gồm 1, 2, 3) nhưng cô ấy chỉ biết tính nếu các số hạng được sắp xếp tăng dần (ví dụ: "1+1+3+2" phải sửa thành "1+1+2+3").
Hãy giúp cô ấy sắp xếp lại biểu thức.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán chuyển đổi **String -> Vector -> String**.
1.  **Parsing:** Chuỗi đầu vào có dạng "s1+s2+s3...". Ta cần tách các con số ra. Vì các số chỉ có 1 chữ số, ta có thể duyệt và lấy các ký tự ở vị trí chẵn (0, 2, 4...) hoặc bỏ qua dấu '+'.
2.  **Lưu trữ:** Đưa các số (hoặc ký tự số) vào một `std::vector`.
3.  **Sắp xếp:** Dùng `std::sort`.
4.  **Tái tạo:** In phần tử đầu tiên, sau đó với mỗi phần tử tiếp theo, in dấu "+" trước rồi đến phần tử đó.

---

### 18. Magnets (Mã bài: 344A)
**Liên kết:** [Codeforces 344A](https://codeforces.com/problemset/problem/344/A)
**Nguồn tham khảo:** [8]

#### Bản dịch Đề bài (Tiếng Việt)
Các thanh nam châm domino có hai cực: "01" (dương-âm) hoặc "10" (âm-dương). Khi xếp nối tiếp, các cực giống nhau sẽ đẩy nhau tạo thành khoảng hở, chia dãy nam châm thành các nhóm. Đếm số lượng nhóm.
Ví dụ: 10 - 10 (hút) - 01 (đẩy, vì 0 gặp 0).

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán đếm số lượng **Chuyển mạch (Transitions)** trong luồng dữ liệu.
Một nhóm mới được hình thành khi và chỉ khi nam châm hiện tại **khác** nam châm ngay trước đó (ví dụ đang là "10" chuyển sang "01"). Nếu giống nhau ("10" tiếp theo "10"), chúng hút nhau và cùng một nhóm.
Thuật toán:
Duyệt từ nam châm thứ 2 đến thứ n. Nếu `current_magnet!= previous_magnet` thì `group_count++`.

---

### 19. Tram (Mã bài: 116A)
**Liên kết:** [Codeforces 116A](https://codeforces.com/problemset/problem/116/A)
**Nguồn tham khảo:** [7]

#### Bản dịch Đề bài (Tiếng Việt)
Tàu điện đi qua $n$ trạm. Tại mỗi trạm có $a_i$ người xuống và $b_i$ người lên. Hãy tính sức chứa tối thiểu cần thiết của tàu để không ai bị thiếu chỗ (tức là tìm số lượng hành khách lớn nhất có mặt trên tàu tại bất kỳ thời điểm nào).

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Mô phỏng **Tổng tiền tố (Prefix Sum)** hoặc **Biến tích lũy (Running Sum)**.
Khởi tạo `current_passengers = 0` và `max_capacity = 0`.
Tại mỗi trạm:
1.  `current_passengers -= a_i` (người xuống).
2.  `current_passengers += b_i` (người lên).
3.  `max_capacity = max(max_capacity, current_passengers)` (cập nhật đỉnh điểm).
Kết quả là `max_capacity`.

---

### 20. Ultra-Fast Mathematician (Mã bài: 61A)
**Liên kết:** [Codeforces 61A](https://codeforces.com/problemset/problem/61/A)
**Nguồn tham khảo:** [8, 33]

#### Bản dịch Đề bài (Tiếng Việt)
Cho hai số nhị phân độ dài bằng nhau. Hãy thực hiện phép toán XOR lên chúng (1 XOR 0 = 1, 0 XOR 1 = 1, còn lại bằng 0).
Lưu ý: Số có thể dài tới 100 chữ số, không thể dùng kiểu `int` hay `long long`.

#### Phân tích Lý thuyết và Chiến lược Giải quyết
Bài toán minh họa việc xử lý **Số lớn (Big Int)** thông qua chuỗi. Vì độ dài quá lớn so với thanh ghi CPU (64-bit), ta phải xử lý từng "bit" dưới dạng ký tự.
Duyệt hai chuỗi song song.
Nếu `s1[i] == s2[i]` -> Kết quả là '0'.
Nếu `s1[i]!= s2[i]` -> Kết quả là '1'.
In trực tiếp kết quả mà không cần lưu trữ trung gian để tiết kiệm bộ nhớ.

---

## Phần III: Kết luận và Lộ trình Phát triển

Việc hoàn thành 20 bài tập này đánh dấu sự chuyển mình từ một người mới làm quen (Newbie) sang một lập trình viên có tư duy thuật toán (Pupil).

**Những kỹ năng cốt lõi đã đạt được:**
1.  **Thao tác String:** Hiểu sâu về ASCII, sự khác biệt giữa ký tự ('5') và số (5), và các hàm thao tác chuỗi.
2.  **Tư duy Vector:** Biết cách sử dụng mảng động để lưu trữ và sắp xếp dữ liệu.
3.  **Tối ưu hóa:** Nhận thức được sự khác biệt giữa $O(N)$ và $O(N^2)$, và khi nào cần dùng thuật toán tham lam.

**Bước tiếp theo:**
Sau khi thành thạo danh sách này, người học nên chuyển sang các chủ đề về:
*   **Lý thuyết Số cơ bản:** Số nguyên tố, UCLN (GCD).
*   **Tìm kiếm Nhị phân (Binary Search).**
*   **Cấu trúc dữ liệu:** Map (`std::map`), Stack, Queue.

Báo cáo này khuyến nghị người học không chỉ nộp bài (submit) cho đến khi đúng (Accepted), mà hãy đọc code của các cao thủ (những người có rank đỏ/cam) để học cách viết code ngắn gọn và "thanh lịch" (clean code) hơn sau khi đã giải được bài.

---
**Thông tin Báo cáo:**
*   **Người thực hiện:** Chuyên gia Đào tạo Lập trình Thi đấu.
*   **Phạm vi:** Codeforces Elo 800-1000.
*   **Ngôn ngữ:** Tiếng Việt.