#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

/**
 * @mainpage Out Of Core Image Processing Liabary
 * 
 * @section intro_sec ����
 * ͨ����ͼ�����ǻ����ڴ���еģ�����ͼ�����ݷǳ������޷�������ȫ��װ���ڴ洦���ʱ�򣬻����ڴ�Ĵ������ͻ�ʧЧ��\n
 * Out Of Core���������������������⡣�����ݺܴ��ʱ��ʵ�ʵ����ݴ����Ӳ���ϣ�����Ҫ��ȡ���ߴ������ݵ�ʱ��
 *�ٶ�̬�ĴӴ����м������ݵ��ڴ���д���\n
 *
 * ��Ҫʵ�������漸���ࣺ
 * - BlockwiseImage �������ɴ��͵��������ݴ��棬�ṩ��ͼ�����ͨ���Խӿڣ�ͬʱ���Խ�ͼ������д�뵽�������Ա���������
 * - HierarchicalImage �̳���BlockwiseImage���ṩһ�µ�ͼ����ӿڣ����ڱ��浽����ʱ������ȡ��ͬ�Ĳ㼶��ͼ�����ݲ�д����̣����������Ժ���ȡ
 *��ͬ�ֱ����µ�ͼ�����ݡ�
 * - DiskBigImage ��������BlockwiseImage��HierarchicalImageд�뵽�����е�ͼ�����ݽ��ж�̬�Ķ�д������
 *
 * ���������ļ�˵����
 * - ReadingBigImage ͼ��������ĳ���ʵ�֡�
 * - Test ��BlockwiseImage��ͼ����ӿں�DiskBigImage�Ķ�д�ӿڽ����˲��ԣ�����һ�����ǹ��ڲ�ͬ���������Ĳ��ԡ�
 * - WriteBlockWiseImage ʹ��BlockwiseImageд��ͼ������
 * - WriteHierarchicalImage ʹ��HierarchicalImageд��ͼ������
 * - TimeConsumeTest ��DiskBigImage���get_pixels_by_level_fast��get_pixels_by_level�ٶ��Ͻ��еĲ��ԡ�
 * \n
 * 
 * @section setup_sec ��װ
 * @subsection libary_sec ��ؿ�
 * <pre>
 * <b>1. boost</b>
 * ʹ�õ���boost����������ӿ⣺
 * data_time iostreams filesystem system thread
 * ��Ҫ���������ľ�̬�⣬���뵽$(BOOST_ROOT)/stage/libĿ¼�£�����BOOST_ROOTΪָ��boost������
 * ��Ŀ¼��ϵͳ����������
 *
 * <b>2. stxxl</b>
 * ��һ���ṩ�˻���stl�������ӿڣ�ͬʱ���������ݴ����Ӳ���еĿ⡣
 * Website : http://stxxl.sourceforge.net/ 
 *
 * ʹ��vc10����õ�lib������OutOfCore/Library/stxxl/libĿ¼���棬�������ֱ�ӱ����������ӣ���ô���±���
 *
 * stxxl��ԭ������ʹ��nmake����Makefile�ķ�ʽ���ݲ�֪�����ֱ�Ӽ��ɵ�cmake�У������ñ�����nmake������
 * stxxl��lib�ļ�
 *
 * ���뷽����
 * ��LibraryĿ¼�µ�stxxlԴ���ѹ,ʹ�����
 * nmake library_msvc_release
 * ����õ�libstxxl.lib�ļ���libĿ¼�£����俽����OutOfCore/Library/stxxl/lib/ReleaseĿ¼����
 * nmake clean_msvc 
 * �����������ɾ��
 * nmake library_msvc_debug
 * ����debug�汾�Ŀ⣬ͬ����libstxxl.lib������OutOfCore/Library/stxxl/lib/DebugĿ¼����
 *  
 * stxxl�������ļ����ڴ������е�Ŀ¼�����½��ļ�config.stxxl
 * For example : #config.stxxl
 * disk=c:\stxxl,70000,wincall     
 * disk=d:\stxxl,70000,wincall
 * disk=e:\stxxl,70000,wincall
 * #��ʾ����c��d��e�зֱ���70000M��С���ļ�stxxl�������������á�
 * #����Out_Of_Coreģ����ԣ���Сȡ����ͼ������ݴ�С������һ��102400*102400��ͼ����ԣ�
 * ���ͼ����RGB����ʽ����ô�ܴ�СΪ30G��ͼ������ʹ����zorder���д洢�������������ࡣ
 * ʹ��zorder��Ϊ������ʽ�Ļ��������Ϊԭ����С��4����һ��Ϊ2�����ң����Է���60G��120G�ȽϺ��ʡ�

 * <b>3. OpenCV</b>
 * ��������˺� SAVE_MINI_IMAGE
 * �ڽ�ͼ��д�뵽�����е�ʱ��ͬʱҲ�����һ�����û�ָ���ֱ��ʴ�С��jpg��ʽͼ���ļ������ļ���ͼ�������ͼ��������õ���ʾЧ��
 * ��ʹ�õ���OpenCV������ģ��
 * core highgui imgproc
 * </pre>
 * @note Ĭ����û�ж���SAVE_MINI_IMAGE
 * \n
 * 
 * @section src_sec Out Of Coreģ�����
 * ���д��붼��ģ��������Ƿ���.h�ļ��е�inline������ֱ��include�������б��뼴�ɡ�\n
 * ���������/Platform/OutOfCore/include/ �ļ�����
 *
 */

#endif
