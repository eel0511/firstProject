
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.InputStreamReader;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import java.net.URL;
import java.net.URLEncoder;
import java.io.BufferedReader;
import java.net.HttpURLConnection;
import java.io.IOException;

public class test {

    // tag값의 정보를 가져오는 메소드
	private static String getTagValue(String tag, Element eElement) {
		if(eElement.getElementsByTagName(tag).item(0)==null){
			return null;
		}
	    NodeList nlList = eElement.getElementsByTagName(tag).item(0).getChildNodes();
	    Node nValue = (Node) nlList.item(0);
	    if(nValue == null) 
	        return null;
	    return nValue.getNodeValue();
	}

	public static void main(String[] args) {
		int page = 1;	// 페이지 초기값
		String str_num = "120";
		int int_num = Integer.parseInt(str_num);
		try{
			while(int_num<311){
				// parsing할 url 지정(API 키 포함해서)
				str_num=Integer.toString(int_num);
				StringBuilder urlBuilder = new StringBuilder("http://apis.data.go.kr/5020000/SmartParkingLotInfo/parkingLotDetail"); /*파싱URL*/
        		String service_key = "WBBFtMijb5OGpPE7TFNxZYLTwj%2Bc%2BdoXfjxXf7GImXSVq%2Fd0oPtZEgegKnNSFVg56JjREXbo7hKf4bYxgdMAKA%3D%3D";
        		urlBuilder.append("?" + URLEncoder.encode("serviceKey","UTF-8") + "="+service_key);
        		urlBuilder.append("&" + URLEncoder.encode("idx","UTF-8") + "=" + URLEncoder.encode(str_num, "UTF-8")); /*주차장의 상세 정보 조회를 위한 주차장 고유값*/
				String url = urlBuilder.toString();
				URL url2 = new URL(urlBuilder.toString());

				DocumentBuilderFactory dbFactoty = DocumentBuilderFactory.newInstance();
				DocumentBuilder dBuilder = dbFactoty.newDocumentBuilder();
				Document doc = dBuilder.parse(url);
				BufferedReader rd;
				
				HttpURLConnection conn = (HttpURLConnection) url2.openConnection();
        		conn.setRequestMethod("GET");
        		conn.setRequestProperty("Content-type", "application/json");
        		//System.out.println("Response code: " + conn.getResponseCode());

				rd = new BufferedReader(new InputStreamReader(conn.getInputStream(), "UTF-8"));
				// root tag 
				doc.getDocumentElement().normalize();
				//System.out.println("Root element :" + doc.getDocumentElement().getNodeName());
				
				// 파싱할 tag
				NodeList nList = doc.getElementsByTagName("response");
				//System.out.println("파싱할 리스트 수 : "+ nList.getLength());
				
				//for(int temp = 0; temp < nList.getLength(); temp++){
					Node nNode = nList.item(0);
					if(nNode.getNodeType() == Node.ELEMENT_NODE){
						
						Element eElement = (Element) nNode;
						
						if(getTagValue("parkingLot_name", eElement)!= null){
							System.out.println("############################################");
							//System.out.println(eElement.getTextContent());
							System.out.println("idx  :  " + getTagValue("idx",eElement));
							System.out.println("주차장 이름  : " + getTagValue("parkingLot_name", eElement));
							System.out.println("날짜  : " + getTagValue("RDate", eElement));
							System.out.println("운영 시간 : " + getTagValue("operation_sTime", eElement));
							System.out.println("위도 경도  : " + getTagValue("location_lon", eElement));
							System.out.println("주소  : " + getTagValue("addr", eElement));
						}
						
					}	// for end
				//}	// if end
				
				/*/*page += 1;
				System.out.println("page number : "+page);
				if(page > 12){	
					break;
				}*/
				Thread.sleep(30);
				int_num++;
			}	// while end
			
		} catch (Exception e){	
		//	e.printStackTrace();
		}	// try~catch end
	}	// main end
}	// class end