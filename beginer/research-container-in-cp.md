Dưới đây là toàn bộ nội dung của báo cáo nghiên cứu về các container trong C++ hiện đại và lập trình thi đấu:

# Báo cáo Nghiên cứu Chuyên sâu: Kiến trúc Container C++ Hiện đại và Các Chiến lược Tối ưu hóa trong Lập trình Thi đấu

## Tóm tắt Điều hành

Thư viện Mẫu Chuẩn (Standard Template Library - STL) trong C++ đại diện cho một trong những khung lập trình tổng quát tinh vi và hiệu quả nhất trong khoa học máy tính hiện đại. Kể từ khi chuẩn C++11 được phê chuẩn, và đặc biệt là thông qua các bước tiến hóa lớn của C++17 và C++20, bức tranh về các cấu trúc lưu trữ dữ liệu (container) đã chuyển dịch mạnh mẽ từ các cơ chế lưu trữ đơn giản sang các trừu tượng hiệu năng cao, tối ưu hóa bộ nhớ và thân thiện với bộ nhớ đệm (cache-friendly). Đối với lập trình viên thi đấu (competitive programmer)—người hoạt động dưới những ràng buộc nghiêm ngặt về thời gian thực thi và bộ nhớ—việc thấu hiểu các sắc thái của những container này không chỉ dừng lại ở cú pháp mà còn là sự sống còn về mặt thuật toán.

Báo cáo này cung cấp một phân tích toàn diện về hệ sinh thái container trong C++, giải quyết câu hỏi cụ thể về các đổi mới được giới thiệu trong C++17 và các phiên bản sau đó, đồng thời mổ xẻ những container đóng vai trò quan trọng nhất trong lập trình thi đấu. Chúng ta sẽ khám phá các mô hình bộ nhớ nội tại, quy tắc vô hiệu hóa iterator (iterator invalidation), độ phức tạp tiệm cận, và các kỹ thuật tối ưu hóa cấp thấp giúp phân biệt việc sử dụng ở trình độ chuyên gia so với người mới bắt đầu. Hơn nữa, báo cáo sẽ điều tra các thư viện "ẩn" hoặc không chuẩn như Cấu trúc Dữ liệu Dựa trên Chính sách (Policy-Based Data Structures - PBDS) trong phần mở rộng GNU C++, cung cấp các khả năng vượt trội mà STL tiêu chuẩn còn thiếu sót.

---

## 1. Sự Tiến hóa của Hệ sinh thái Container C++ và Tác động đến Hiệu năng

Lịch sử phát triển của container C++ luôn ưu tiên các trừu tượng có chi phí bằng không (zero-overhead abstractions). Tuy nhiên, các tiêu chuẩn gần đây (C++17, C++20, C++23) đã giới thiệu một sự thay đổi mô hình hướng tới lập trình dựa trên "view" (khung nhìn) và tính đa hình của bộ nhớ, thay đổi căn bản cách dữ liệu được truy cập và thao tác mà không phải chịu chi phí sở hữu.

### 1.1 Bối cảnh trước C++17: Kỷ nguyên của Container Sở hữu

Trước C++17, thư viện container bị chi phối bởi các container sở hữu tài nguyên (owning containers): `std::vector`, `std::list`, `std::map`, và các phiên bản không thứ tự (unordered) của chúng. Các cấu trúc này tự quản lý bộ nhớ của chính mình, buộc phải thực hiện sao chép sâu (deep copy) khi truyền dữ liệu trừ khi ngữ nghĩa di chuyển (move semantics - C++11) được kích hoạt rõ ràng. Mặc dù mạnh mẽ, mô hình này tạo ra sự dư thừa trong bối cảnh lập trình thi đấu (Competitive Programming - CP), đặc biệt là khi xử lý các chuỗi con hoặc mảng con, dẫn đến việc cấp phát bộ nhớ động không cần thiết và làm tăng thời gian thực thi tổng thể.

### 1.2 Cuộc Cách mạng C++17: Views và Đa hình Bộ nhớ

Truy vấn của người dùng đặc biệt quan tâm đến các container mới trong C++17. Mặc dù C++17 không giới thiệu hàng loạt container tuần tự *sở hữu* mới theo nghĩa truyền thống (như một loại `vector` mới), nó đã giới thiệu các "kiểu từ vựng" (vocabulary types) quan trọng và các cơ chế thay đổi hành vi của container hiện có, đóng vai trò như các giả container (pseudo-containers) tối ưu hóa hiệu suất.

#### 1.2.1 `std::string_view` (C++17): Siêu vũ khí Xử lý Chuỗi

Mặc dù về mặt kỹ thuật là một "view" thay vì một container lưu trữ, `std::string_view` là sự bổ sung quan trọng nhất cho các tác vụ xử lý văn bản hiệu năng cao. Nó hoạt động như một tham chiếu không sở hữu tới một chuỗi ký tự, chỉ bao gồm một con trỏ và một độ dài.
Cơ chế hoạt động của `std::string_view` giải quyết triệt để vấn đề cấp phát bộ nhớ của `std::string`. Trong `std::string`, dữ liệu thường được cấp phát trên heap (trừ khi Tối ưu hóa Chuỗi Nhỏ - SSO được áp dụng) và sao chép dữ liệu khi truyền tham trị hoặc tạo chuỗi con. Ngược lại, `std::string_view` là một tay cầm (handle) nhẹ. Trong các bài toán CP liên quan đến băm chuỗi (string hashing), cấu trúc hậu tố (suffix structures), hoặc phân tích cú pháp đầu vào lớn (parsing), việc thay thế `const std::string&` bằng `std::string_view` giúp loại bỏ hoàn toàn các cấp phát tạm thời. Phân tích cho thấy khả năng tạo chuỗi con (`substr`) trong thời gian  và không gian  là lợi thế tuyệt đối so với  của `std::string` truyền thống.

#### 1.2.2 Tài nguyên Bộ nhớ Đa hình (`std::pmr`) (C++17)

C++17 đã giới thiệu header `<memory_resource>` và không gian tên `std::pmr`. Điều này cho phép các container thay đổi chiến lược cấp phát bộ nhớ tại thời gian chạy (runtime) thay vì thời gian biên dịch (compile-time).
Các kiểu dữ liệu mới bao gồm `std::pmr::vector`, `std::pmr::list`, `std::pmr::map`, v.v. Về bản chất, chúng giống hệt các đối tác `std` thông thường nhưng sử dụng `std::pmr::polymorphic_allocator`. Ý nghĩa của việc này trong lập trình thi đấu là khả năng sử dụng các bộ đệm đơn điệu dựa trên ngăn xếp (stack-based monotonic buffers) cho các container. Việc này giúp giảm thiểu chi phí của các lệnh gọi hệ thống `new`/`delete`, vốn rất tốn kém về thời gian. Mặc dù là một kỹ thuật nâng cao, đây là công cụ mạnh mẽ để tối ưu hóa các bài toán yêu cầu hàng triệu thao tác cấp phát nhỏ, giúp giảm đáng kể thời gian chạy trong các bài toán có giới hạn thời gian cực gắt (ví dụ: 0.5 giây).

#### 1.2.3 Container chứa Trạng thái: `std::variant`, `std::optional`, `std::any` (C++17)

Mặc dù không phải là container chứa dãy phần tử, các kiểu này là container chứa *trạng thái* hoặc *giá trị đơn lẻ*.
`std::optional<T>` chứa một giá trị hoặc không chứa gì, thay thế cho mẫu thiết kế "pair với boolean" (`pair<T, bool>`) thường được sử dụng trong các thuật toán tìm kiếm trên đồ thị để biểu thị trạng thái đã thăm hoặc kết quả hợp lệ.
`std::variant<T...>` là một liên hợp an toàn kiểu (type-safe union). Trong CP, cấu trúc này cực kỳ hữu ích cho các trình phân tích cú pháp đệ quy (recursive parsers) hoặc các cây cú pháp trừu tượng (Abstract Syntax Trees - AST), nơi một nút có thể chứa các kiểu dữ liệu khác nhau mà không cần chi phí thừa kế (inheritance overhead) và con trỏ ảo (vtable).

### 1.3 Các Đổi mới sau C++17 (C++20 và C++23)

Để cung cấp một cái nhìn toàn diện, cần xem xét các tính năng sau C++17 vì chúng đang dần trở nên khả dụng trên các nền tảng chấm bài trực tuyến hiện đại (ví dụ: Codeforces, AtCoder hỗ trợ C++20/23).
`std::span` (C++20) là sự tổng quát hóa của `std::string_view` cho bộ nhớ liền kề bất kỳ (mảng, vector). Nó cho phép các hàm chấp nhận một lát cắt của `vector` hoặc một mảng thô một cách đồng nhất, thiết yếu cho các thuật toán chia để trị mà không cần truyền cặp iterator rườm rà.
`std::flat_map` và `std::flat_set` (C++23) là các bộ chuyển đổi container cung cấp giao diện của map/set nhưng lưu trữ dữ liệu trong các `std::vector` được sắp xếp. Chúng cung cấp khả năng tìm kiếm  nhưng với tính địa phương bộ nhớ đệm (cache locality) tốt hơn đáng kể so với các map dựa trên nút (node-based), làm cho chúng vượt trội trong các tác vụ CP nặng về đọc dữ liệu.

---

## 2. Container Tuần tự (Sequence Containers): Xương sống của Lập trình Thi đấu

Trong lập trình thi đấu, việc lựa chọn container tuần tự quyết định hiệu năng cơ sở của thuật toán. Chúng ta sẽ phân tích các lựa chọn tiêu chuẩn với trọng tâm là cơ chế nội tại và tính phù hợp với các giới hạn tài nguyên.

### 2.1 `std::vector`: Sự Lựa chọn Mặc định

`std::vector` là một mảng động đảm bảo lưu trữ bộ nhớ liền kề. Đây là "ngựa thồ" của CP nhờ sự thân thiện với bộ nhớ đệm CPU (CPU cache friendliness).

#### Cơ chế Tăng trưởng và Chiến lược `reserve()`

Khi dung lượng (capacity) bị vượt quá, `std::vector` thường tăng gấp đôi kích thước (hệ số tăng trưởng là 1.5 hoặc 2, tùy thuộc vào trình biên dịch). Điều này đảm bảo độ phức tạp khấu hao (amortized complexity) là  cho thao tác `push_back`. Tuy nhiên, trong môi trường thi đấu, việc tái cấp phát bộ nhớ là một tác vụ tốn kém. Chiến lược tối ưu là sử dụng `reserve()`: nếu biết trước số lượng phần tử  (thường được cung cấp ở đầu input), lệnh `v.reserve(N)` sẽ ngăn chặn hoàn toàn việc tái cấp phát và sao chép dữ liệu, thường giúp giảm thời gian đọc dữ liệu từ 20-30% trong các bài toán input lớn.

#### Sự Khác biệt giữa Size và Capacity

Một lỗi phổ biến trong các bài toán đa testcase (multi-testcase problems) là hiểu sai về `clear()`. Hàm `clear()` chỉ đặt kích thước (`size`) về 0 nhưng không giải phóng bộ nhớ đã cấp phát (`capacity` giữ nguyên). Điều này có lợi cho hiệu năng vì tránh cấp phát lại trong các testcase sau, nhưng có thể gây lỗi Tràn bộ nhớ (Memory Limit Exceeded - MLE) nếu vector quá lớn. Trong trường hợp cần giải phóng bộ nhớ thực sự, thành ngữ `vector<T>().swap(v)` hoặc phương thức `shrink_to_fit()` (C++11) là cần thiết.

### 2.2 `std::array` so với `std::vector`: Tối ưu hóa Ngăn xếp

Được giới thiệu trong C++11, `std::array` là một lớp bọc mỏng xung quanh mảng kiểu C cố định kích thước.
Về mặt hiệu năng, `std::array` cấp phát trên ngăn xếp (stack) nếu được khai báo cục bộ hoặc phân đoạn dữ liệu tĩnh (static data segment) nếu là biến toàn cục. Nó chịu chi phí bằng không cho việc cấp phát so với cấp phát heap của `std::vector`. Trong CP, `std::array` được ưu tiên cho các bộ đệm kích thước nhỏ, cố định (ví dụ: ma trận nhân trong quy hoạch động, các cặp tọa độ hướng di chuyển trên lưới `dx/dy`) nơi kích thước được biết tại thời gian biên dịch. Nó tích hợp với các thuật toán C++ (`std::sort`, `std::fill`) tốt hơn và an toàn hơn mảng thô C.

### 2.3 `std::deque`: Hàng đợi Hai đầu và Cấu trúc Phân mảnh

`std::deque` (double-ended queue) thường bị hiểu nhầm là một vector danh sách liên kết. Thực tế, về mặt nội tại, nó **không** phải là một khối liền kề mà là một tập hợp các khối bộ nhớ kích thước cố định (thường là 512 bytes hoặc kích thước của một phần tử nếu lớn hơn) được quản lý bởi một thư mục trung tâm (mảng các con trỏ).
Ưu điểm lớn nhất là khả năng chèn/xóa  ở cả hai đầu. Quan trọng hơn, con trỏ tới các phần tử không bị vô hiệu hóa khi đẩy/lấy phần tử ở các đầu (khác với vector).
Trong lập trình thi đấu, `std::deque` là không thể thay thế cho bài toán **Sliding Window Maximum** (Tìm giá trị lớn nhất trong cửa sổ trượt) sử dụng kỹ thuật Hàng đợi Đơn điệu (Monotonic Queue), cho phép giải quyết các bài toán truy vấn phạm vi với độ phức tạp . Ngoài ra, nó cũng là cấu trúc cốt lõi cho thuật toán **0-1 BFS** (tìm đường đi ngắn nhất trên đồ thị có trọng số cạnh là 0 hoặc 1).

### 2.4 `std::list` và `std::forward_list`: Tại sao nên tránh?

`std::list` (danh sách liên kết đôi) hiếm khi được sử dụng trong CP do việc truy cập bộ nhớ phân tán (pointer chasing), gây ra lỗi cache miss liên tục và tốc độ duyệt chậm. Lợi thế duy nhất của nó là khả năng nối (`splice`) các chuỗi trong  và xóa phần tử ở giữa khi đã có iterator.
`std::forward_list` (danh sách liên kết đơn, C++11) hiệu quả hơn về bộ nhớ so với `list` nhưng thiếu hàm `push_back` và `size()` (việc đếm kích thước tốn ). Trừ khi đang triển khai thủ công một bảng băm xử lý va chạm bằng chuỗi (chaining) hoặc giải bài toán tối ưu hóa cực đoan về bộ nhớ (như Dancing Links), `std::forward_list` hầu như không có chỗ đứng trong CP.

---

## 3. Container Liên kết (Associative Containers) và Các Cải tiến C++17

Các container liên kết (`std::set`, `std::map`) thường được triển khai dưới dạng Cây Đỏ-Đen (Red-Black Trees), đảm bảo chiều cao cân bằng và các thao tác trong thời gian .

### 3.1 Kỹ thuật Nối Node (Node Splicing) - Tính năng C++17

Một trong những tính năng mạnh mẽ nhưng ít được tận dụng nhất trong CP được giới thiệu trong C++17 là **Trích xuất và Nối Node** (Node Extraction and Splicing).
Vấn đề truyền thống: Việc di chuyển một phần tử từ `std::set` này sang `std::set` khác, hoặc thay đổi khóa (key) của một phần tử trong `std::map`, trước đây yêu cầu xóa node cũ và cấp phát node mới. Thao tác này có độ phức tạp  nhưng đi kèm với chi phí ẩn rất lớn của việc gọi `new`/`delete` và sao chép dữ liệu.
Giải pháp C++17: Hàm `.extract()` cho phép ngắt liên kết node khỏi cây mà không giải phóng bộ nhớ.

* `auto node = myMap.extract(iterator);` tách node ra.
* `node.key() = new_key;` cho phép sửa đổi key trực tiếp trên node (điều trước đây bị cấm).
* `myMap.insert(std::move(node));` chèn lại node vào cây.
Lợi ích trong CP: Tính năng này cho phép gộp các set hoặc map (`set1.merge(set2)`) với chi phí cấp phát bằng 0, chỉ đơn thuần là thay đổi các con trỏ nội bộ. Đây là kỹ thuật tối quan trọng cho các thuật toán "Gộp Nhỏ vào Lớn" (Small-to-Large Merging) thường dùng trong các bài toán quy hoạch động trên cây (Tree DP) hoặc DSU, giúp giảm hằng số thời gian đáng kể.

### 3.2 Bộ so sánh Trong suốt (Transparent Comparators) và Tra cứu Không đồng nhất

Trong các map tiêu chuẩn, lệnh `find("key")` trên một `std::map<std::string, int>` sẽ tạo ra một đối tượng `std::string` tạm thời, gây cấp phát bộ nhớ.
Từ C++14/17, bằng cách sử dụng `std::map<std::string, int, std::less<>>` (chú ý tham số template `void`), ta kích hoạt **tra cứu không đồng nhất** (heterogeneous lookup). Điều này cho phép truy vấn map bằng `std::string_view` hoặc `const char*` mà không cần tạo đối tượng `std::string`, tiết kiệm thời gian cấp phát trong các vòng lặp chặt chẽ.

---

## 4. Container Không thứ tự (Unordered) và Chiến lược Băm trong CP

`std::unordered_map` và `std::unordered_set` là các bảng băm. Mặc dù về lý thuyết có độ phức tạp trung bình là , chúng ẩn chứa rủi ro tử thần trong CP: **Các bài test chống băm (Anti-Hash Tests)**.

### 4.1 Lỗ hổng Bảo mật Thuật toán

Thư viện chuẩn C++ sử dụng một hàm băm cụ thể (thường là MurmurHash hoặc CityHash tùy trình biên dịch) có tính xác định. Trên các nền tảng như Codeforces, những người tạo đề hoặc hacker có thể tạo ra các bộ test được thiết kế đặc biệt để gây ra va chạm băm (hash collisions) hàng loạt (ví dụ: chèn các số là bội của số nguyên tố được dùng trong hàm băm). Điều này làm suy giảm hiệu năng xuống  cho mỗi thao tác, dẫn đến lỗi Quá giới hạn thời gian (Time Limit Exceeded - TLE).

### 4.2 Giải pháp: Hàm Băm Tùy biến (Custom Hash Functions)

Để sử dụng `unordered_map` an toàn, lập trình viên thi đấu bắt buộc phải sử dụng hàm băm tùy biến kết hợp với hạt giống ngẫu nhiên từ đồng hồ độ phân giải cao (high-resolution clock) để ngẫu nhiên hóa cơ sở băm. Hàm `SplitMix64` thường được ưa chuộng vì độ phân tán bit tốt.

**Bảng 1: So sánh `std::map` và `std::unordered_map` trong Lập trình Thi đấu**

| Đặc điểm | `std::map` | `std::unordered_map` (Mặc định) | `std::unordered_map` (Custom Hash) |
| --- | --- | --- | --- |
| **Cấu trúc dữ liệu** | Cây Đỏ-Đen | Bảng băm (Chaining) | Bảng băm (Chaining) |
| **Độ phức tạp (TB)** |  |  |  |
| **Độ phức tạp (Worst)** |  |  (Dễ bị hack) |  (Khó bị hack) |
| **Thứ tự phần tử** | Có sắp xếp | Ngẫu nhiên | Ngẫu nhiên |
| **Yêu cầu bộ nhớ** | Cao (mỗi node 2 con trỏ + màu) | Cao (mảng bucket + node) | Cao |
| **Khuyến nghị CP** | Dùng khi cần thứ tự hoặc  | **KHÔNG NÊN DÙNG** | Dùng cho truy vấn  an toàn |

---

## 5. Các Cấu trúc Chuyên biệt cho Tối ưu hóa Thuật toán

Ngoài các container chuẩn, một số cấu trúc đặc thù cung cấp lợi thế tiệm cận cho các lớp bài toán riêng biệt.

### 5.1 `std::bitset`: Tối ưu Không gian và Thời gian

`std::bitset` là một template class lưu trữ các bit một cách nén (1 bit mỗi phần tử, thay vì 1 byte như `bool`).
Hiệu quả của nó nằm ở khả năng thực hiện các phép toán bit (`&`, `|`, `^`, `~`) trên toàn bộ tập hợp trong thời gian  (mô phỏng song song hóa 64-bit). Trong CP, nó được dùng cho bài toán Cái túi (Knapsack reachability), giải hệ phương trình boolean (khử Gauss trên trường GF(2)), và tối ưu hóa so khớp đồ thị.
**Viên ngọc ẩn của GCC**: `std::bitset` trong trình biên dịch GCC có hai hàm mở rộng không chuẩn nhưng cực kỳ mạnh mẽ: `_Find_first()` và `_Find_next(k)`. Các hàm này ánh xạ trực tiếp tới các chỉ thị CPU (như `ctz` - đếm số bit 0 ở đuôi), cho phép duyệt qua các bit đang bật (set bits) với tốc độ cực nhanh, bỏ qua các bit 0 một cách hiệu quả.

### 5.2 Tranh cãi về `std::vector<bool>`

`std::vector<bool>` là một chuyên biệt hóa của template vector giúp nén bit (1 bit mỗi boolean). Tuy nhiên, nó thường bị chỉ trích vì:

1. Không phải là một container đúng nghĩa (không trả về tham chiếu `bool&` mà trả về đối tượng proxy).
2. Chậm hơn `std::bitset` đối với kích thước cố định.
Trong CP, nếu kích thước đã biết tại thời gian biên dịch, hãy dùng `std::bitset`. Nếu kích thước động, `std::vector<char>` hoặc `std::vector<int>` thường được ưu tiên hơn để tránh chi phí truy cập của đối tượng proxy, trừ khi bộ nhớ cực kỳ hạn hẹp.

### 5.3 `std::priority_queue` và Lambda Comparator

Là lớp bọc của Binary Heap. Mặc định nó sử dụng `std::vector` làm container nền.
Trong C++11/14, việc viết struct so sánh tùy biến khá dài dòng. Từ C++17/20, lambda có thể được truyền trực tiếp vào hàm dựng với khả năng suy diễn kiểu (deduction guides), đơn giản hóa việc triển khai các thuật toán như Dijkstra hay Prim.

---

## 6. Vũ khí Bí mật: Cấu trúc Dữ liệu Dựa trên Chính sách (PBDS)

Có lẽ vũ khí quan trọng nhất trong lập trình thi đấu C++ mà không nằm trong chuẩn ISO là thư viện Cấu trúc Dữ liệu Dựa trên Chính sách (PBDS), có sẵn trong trình biên dịch GCC (được sử dụng bởi Codeforces, AtCoder, v.v.).

### 6.1 Ordered Set (`tree`)

`std::set` chuẩn cho phép tìm kiếm phần tử, nhưng không hỗ trợ:

1. **Find by Order**: Tìm phần tử nhỏ thứ .
2. **Order of Key**: Tìm thứ hạng (index) của một phần tử cụ thể.

PBDS triển khai một Cây Đỏ-Đen có duy trì kích thước cây con (subtree sizes), cho phép thực hiện hai thao tác trên trong thời gian .
Cấu trúc này (`tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>`) là giải pháp chuẩn mực cho các bài toán đếm nghịch thế, duy trì trung vị động, hoặc truy vấn thứ hạng động mà nếu không dùng PBDS sẽ phải cài đặt Segment Tree hoặc Fenwick Tree phức tạp.

### 6.2 Bảng băm PBDS (`cc_hash_table` và `gp_hash_table`)

PBDS cung cấp các bảng băm (`cc` = chaining collision, `gp` = general probing). Các bảng băm này thường nhanh hơn đáng kể so với `std::unordered_map` do chúng không tuân thủ các yêu cầu nghiêm ngặt về độ ổn định iterator của chuẩn C++, cho phép bố trí bộ nhớ nội bộ thân thiện với cache hơn. `gp_hash_table` thường được coi là bảng băm nhanh nhất có sẵn trong môi trường thi đấu.

---

## 7. Các Chiến lược Chọn lựa Container

Dựa trên phân tích kỹ thuật, bảng sau đây tổng hợp các khuyến nghị chọn lựa container tối ưu cho các kịch bản thi đấu cụ thể.

**Bảng 2: Chiến lược Chọn Container Tối ưu**

| Kịch bản / Yêu cầu | Container Khuyến nghị | Lý do Kỹ thuật & Tối ưu hóa |
| --- | --- | --- |
| Mảng kích thước cố định, nhỏ | `std::array` | Cấp phát Stack, không overhead, an toàn kiểu. |
| Mảng kích thước động | `std::vector` | Cache locality tốt nhất, dùng `reserve()` để tối ưu. |
| Xử lý chuỗi (đọc/so sánh) | `std::string_view` (C++17) | Zero-copy, substring , tránh cấp phát heap. |
| Sliding Window Min/Max | `std::deque` | Hỗ trợ thao tác 2 đầu , Monotonic Queue. |
| Tập hợp cần thứ tự & -th | `pbds::ordered_set` | Hỗ trợ Order Statistics  mà STL thiếu. |
| Tập hợp cần tra cứu  | `gp_hash_table` / Custom `unordered_map` | Nhanh hơn `std::map`, cần custom hash để tránh TLE. |
| Tập hợp bit / Knapsack | `std::bitset` | Nhanh hơn 64 lần nhờ bitwise ops, dùng `_Find_first`. |
| Gộp tập hợp (Small-to-Large) | `std::set` / `std::map` | Dùng `.merge()` (C++17) để chuyển node . |
| Hàng đợi ưu tiên | `std::priority_queue` | Nhanh hơn `set` do dùng Heap (mảng) thay vì Tree (con trỏ). |

---

## 8. Kết luận

Hệ sinh thái container của C++ đã phát triển thành một tập hợp công cụ linh hoạt, hỗ trợ cả sự trừu tượng hóa cấp cao và tối ưu hóa cấp thấp. Đối với câu hỏi về **C++17**, mặc dù không giới thiệu các container lưu trữ chính mới, nhưng việc bổ sung `std::string_view`, các container `std::pmr`, và API trích xuất node (`extract/merge`) cho các container liên kết đã thay đổi căn bản cách dữ liệu được truy cập và chuyển giao, phù hợp hoàn hảo với nhu cầu tối ưu hóa cực đoan của lập trình thi đấu.

Để đạt được hiệu suất cao nhất trong các kỳ thi, lập trình viên không chỉ cần thành thạo các container chuẩn như `vector` và `priority_queue` mà còn phải biết tích hợp các tính năng hiện đại (C++17/20) và các phần mở rộng trình biên dịch (PBDS, GCC bitset). Việc hiểu rõ cơ chế quản lý bộ nhớ, tính địa phương của dữ liệu, và các cạm bẫy thuật toán (như va chạm băm) chính là yếu tố phân định trình độ trong kỷ nguyên lập trình thi đấu hiện đại.