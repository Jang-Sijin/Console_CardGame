using System;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

class TCPClient
{
    static async Task Main(string[] args)
    {
        try
        {
            Console.Write("사용할 닉네임을 입력해주세요: ");
            string nickName = Console.ReadLine();
            Console.WriteLine();

            // 서버에 연결
            TcpClient client = new TcpClient("172.30.1.89", 13000); // 서버의 IP 주소와 포트로 연결
            Console.WriteLine("서버에 연결되었습니다.");

            NetworkStream stream = client.GetStream();

            // 서버로부터의 응답을 받는 메서드
            async Task ReceiveResponseAsync()
            {
                try
                {
                    while (true)
                    {
                        byte[] responseData = new byte[1024];
                        int bytesRead = await stream.ReadAsync(responseData, 0, responseData.Length);
                        string response = Encoding.UTF8.GetString(responseData, 0, bytesRead);
                        Console.WriteLine(">>" + response);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("오류: " + e.Message);
                }
            }

            // 서버로부터의 응답을 비동기적으로 받는 스레드 시작
            Task receiveTask = ReceiveResponseAsync();

            // 메시지 입력 및 전송
            Console.Write("메시지를 입력하세요 (종료하려면 'exit' 입력): ");
            while (true)
            {
                string message = Console.ReadLine();
                if (message.ToLower() == "exit")
                    break;

                message = nickName + ": " + message;

                byte[] data = Encoding.UTF8.GetBytes(message);
                await stream.WriteAsync(data, 0, data.Length);
            }

            // 연결 종료
            stream.Close();
            client.Close();
        }
        catch (Exception e)
        {
            Console.WriteLine("오류: " + e.Message);
        }
    }
}
