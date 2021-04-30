function blogReport(params,deltype,blog_ids){
  if(!deltype)
    deltype='';
  if(!blog_ids)
    blog_ids='';
  if(params){
    jQuery.colorbox({
       href:"/report.php?"+params+'&del_type='+deltype+'&blog_ids='+blog_ids,
       iframe:true,
       innerWidth:500,
       innerHeight:550
    });
  }
}
