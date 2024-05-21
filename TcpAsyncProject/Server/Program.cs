using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

class TCPServer
{
    static Dictionary<TcpClient, NetworkStream> clients = new Dictionary<TcpClient, NetworkStream>();

    static void Main(string[] args)
    {
        TcpListener server = null; // 리스너 객체 생성해서 내가 리스너 서버 역할을 하겠다.
        try
        {
            // 서버 소켓을 생성하고 13000 포트로 바인딩
            IPAddress ipAddress = IPAddress.Parse("172.30.1.89"); // Sever의 IPv4 주소로 아이피를 설정한다.
            server = new TcpListener(ipAddress, 13000);
            server.Start();

            // 클라이언트의 연결을 수락하고 스레드를 시작하여 각 클라이언트와 통신
            Console.WriteLine("서버 시작. 클라이언트의 연결을 기다립니다...");

            while (true)
            {
                TcpClient client = server.AcceptTcpClient();
                NetworkStream stream = client.GetStream();
                Console.WriteLine("서버 시작. 클라이언트의 연결을 기다립니다...");
                clients.Add(client, stream);

                Thread clientThread = new Thread(() => HandleClient(client));
                clientThread.Start();
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("오류: " + e.Message);
        }
        finally
        {
            server.Stop();
        }
    }

    static void HandleClient(TcpClient client)
    {
        NetworkStream stream = clients[client];
        byte[] buffer = new byte[1024];
        int bytesRead;

        try
        {
            while ((bytesRead = stream.Read(buffer, 0, buffer.Length)) != 0)
            {
                // 수신한 데이터를 모든 클라이언트에게 전송하는 대신, 메시지를 보낸 클라이언트에게만 전송
                string data = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                Console.WriteLine($"수신: {data}");

                // 메시지를 보낸 클라이언트를 제외한 모든 클라이언트에게 메시지를 전송
                foreach (var otherClientStream in clients.Values)
                {
                    if (otherClientStream != stream)
                    {
                        otherClientStream.Write(buffer, 0, bytesRead);
                    }
                }
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("오류: " + e.Message);
        }
        finally
        {
            clients.Remove(client);
            stream.Close();
            client.Close();
        }
    }
}