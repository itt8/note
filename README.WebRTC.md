# WebRTC National Source #

https://source.codeaurora.org/


## depot_tools ##
https://source.codeaurora.org/quic/lc/chromium/tools/depot_tools

## replace url in gclient_scm.py ##
	class GitWrapper(SCMWrapper):
		"""Wrapper for Git"""
		name = 'git'
		remote = 'origin'

		cache_dir = None

		def __init__(self, url=None, *args, **kwargs):
		"""Removes 'git+' fake prefix from git URL."""
		if url.startswith('git+http://') or url.startswith('git+https://'):
			url = url[4:]

		prefix_china='source.codeaurora.org/quic/lc'
		url = url.replace('swiftshader.googlesource.com', 'github.com/google')
		url = url.replace('chromium.googlesource.com/external/swarming.client', 'github.com/AtariOS/swarming.client')
		url = url.replace('android.googlesource.com/platform/external/deqp', 'github.com/elongbug/deqp')
		url = url.replace('boringssl.googlesource.com', 'github.com/google')
		if re.match('^.*chromium\.googlesource\.com\\/.+\.git', url):
			url = url.replace('.git', '').replace('chromium.googlesource.com', prefix_china)
		url = url.replace('webrtc.googlesource.com/src', 'github.com/merlindu/WebRTC')
		url = url.replace('webrtc.googlesource.com', prefix_china+'/external/webrtc').replace('.git', '')


## get source ##
	git clone https://source.codeaurora.org/quic/lc/chromium/tools/depot_tools
	#add depot_tools path to env PATH
	mkdir webrtc-checkout
	cd webrtc-checkout
	fetch --nohooks webrtc
	gclient sync

## update code ##
	git checkout master
	git pull origin master
	gclient sync

