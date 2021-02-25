#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/platform/default/logging.h"
#include "tensorflow/core/framework/shape_inference.h"
#include<cmath>


using namespace tensorflow;
#include "HeatEquation.h"


REGISTER_OP("HeatEquation")

.Input("u : double")
.Input("f : double")
.Input("kappa : double")
.Input("dt : double")
.Input("dx : double")
.Input("m : int64")
.Input("n : int64")
.Output("out : double")
.SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {
    
        shape_inference::ShapeHandle u_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(0), 1, &u_shape));
        shape_inference::ShapeHandle f_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(1), 1, &f_shape));
        shape_inference::ShapeHandle kappa_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(2), 1, &kappa_shape));
        shape_inference::ShapeHandle dt_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(3), 0, &dt_shape));
        shape_inference::ShapeHandle dx_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(4), 0, &dx_shape));
        shape_inference::ShapeHandle m_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(5), 0, &m_shape));
        shape_inference::ShapeHandle n_shape;
        TF_RETURN_IF_ERROR(c->WithRank(c->input(6), 0, &n_shape));

        c->set_output(0, c->Vector(-1));
    return Status::OK();
  });

REGISTER_OP("HeatEquationGrad")

.Input("grad_out : double")
.Input("out : double")
.Input("u : double")
.Input("f : double")
.Input("kappa : double")
.Input("dt : double")
.Input("dx : double")
.Input("m : int64")
.Input("n : int64")
.Output("grad_u : double")
.Output("grad_f : double")
.Output("grad_kappa : double")
.Output("grad_dt : double")
.Output("grad_dx : double")
.Output("grad_m : int64")
.Output("grad_n : int64");


class HeatEquationOp : public OpKernel {
private:
  
public:
  explicit HeatEquationOp(OpKernelConstruction* context) : OpKernel(context) {

  }

  void Compute(OpKernelContext* context) override {    
    DCHECK_EQ(7, context->num_inputs());
    
    
    const Tensor& u = context->input(0);
    const Tensor& f = context->input(1);
    const Tensor& kappa = context->input(2);
    const Tensor& dt = context->input(3);
    const Tensor& dx = context->input(4);
    const Tensor& m = context->input(5);
    const Tensor& n = context->input(6);
    
    
    const TensorShape& u_shape = u.shape();
    const TensorShape& f_shape = f.shape();
    const TensorShape& kappa_shape = kappa.shape();
    const TensorShape& dt_shape = dt.shape();
    const TensorShape& dx_shape = dx.shape();
    const TensorShape& m_shape = m.shape();
    const TensorShape& n_shape = n.shape();
    
    
    DCHECK_EQ(u_shape.dims(), 1);
    DCHECK_EQ(f_shape.dims(), 1);
    DCHECK_EQ(kappa_shape.dims(), 1);
    DCHECK_EQ(dt_shape.dims(), 0);
    DCHECK_EQ(dx_shape.dims(), 0);
    DCHECK_EQ(m_shape.dims(), 0);
    DCHECK_EQ(n_shape.dims(), 0);

    // extra check
        
    // create output shape
    int N = u_shape.dim_size(0);
    TensorShape out_shape({N});
            
    // create output tensor
    
    Tensor* out = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(0, out_shape, &out));
    
    // get the corresponding Eigen tensors for data access
    
    auto u_tensor = u.flat<double>().data();
    auto f_tensor = f.flat<double>().data();
    auto kappa_tensor = kappa.flat<double>().data();
    auto dt_tensor = dt.flat<double>().data();
    auto dx_tensor = dx.flat<double>().data();
    auto m_tensor = m.flat<int64>().data();
    auto n_tensor = n.flat<int64>().data();
    auto out_tensor = out->flat<double>().data();   

    forward(out_tensor, u_tensor, f_tensor, kappa_tensor, *dt_tensor, *dx_tensor, *m_tensor, *n_tensor);
 
  }
};
REGISTER_KERNEL_BUILDER(Name("HeatEquation").Device(DEVICE_CPU), HeatEquationOp);



class HeatEquationGradOp : public OpKernel {
private:
  
public:
  explicit HeatEquationGradOp(OpKernelConstruction* context) : OpKernel(context) {
    
  }
  
  void Compute(OpKernelContext* context) override {
    
    
    const Tensor& grad_out = context->input(0);
    const Tensor& out = context->input(1);
    const Tensor& u = context->input(2);
    const Tensor& f = context->input(3);
    const Tensor& kappa = context->input(4);
    const Tensor& dt = context->input(5);
    const Tensor& dx = context->input(6);
    const Tensor& m = context->input(7);
    const Tensor& n = context->input(8);
    
    
    const TensorShape& grad_out_shape = grad_out.shape();
    const TensorShape& out_shape = out.shape();
    const TensorShape& u_shape = u.shape();
    const TensorShape& f_shape = f.shape();
    const TensorShape& kappa_shape = kappa.shape();
    const TensorShape& dt_shape = dt.shape();
    const TensorShape& dx_shape = dx.shape();
    const TensorShape& m_shape = m.shape();
    const TensorShape& n_shape = n.shape();
    
    
    DCHECK_EQ(grad_out_shape.dims(), 1);
    DCHECK_EQ(out_shape.dims(), 1);
    DCHECK_EQ(u_shape.dims(), 1);
    DCHECK_EQ(f_shape.dims(), 1);
    DCHECK_EQ(kappa_shape.dims(), 1);
    DCHECK_EQ(dt_shape.dims(), 0);
    DCHECK_EQ(dx_shape.dims(), 0);
    DCHECK_EQ(m_shape.dims(), 0);
    DCHECK_EQ(n_shape.dims(), 0);


    // create output shape
    
    TensorShape grad_u_shape(u_shape);
    TensorShape grad_f_shape(f_shape);
    TensorShape grad_kappa_shape(kappa_shape);
    TensorShape grad_dt_shape(dt_shape);
    TensorShape grad_dx_shape(dx_shape);
    TensorShape grad_m_shape(m_shape);
    TensorShape grad_n_shape(n_shape);
            
    // create output tensor
    
    Tensor* grad_u = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(0, grad_u_shape, &grad_u));
    Tensor* grad_f = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(1, grad_f_shape, &grad_f));
    Tensor* grad_kappa = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(2, grad_kappa_shape, &grad_kappa));
    Tensor* grad_dt = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(3, grad_dt_shape, &grad_dt));
    Tensor* grad_dx = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(4, grad_dx_shape, &grad_dx));
    Tensor* grad_m = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(5, grad_m_shape, &grad_m));
    Tensor* grad_n = NULL;
    OP_REQUIRES_OK(context, context->allocate_output(6, grad_n_shape, &grad_n));
    
    // get the corresponding Eigen tensors for data access
    
    auto u_tensor = u.flat<double>().data();
    auto f_tensor = f.flat<double>().data();
    auto kappa_tensor = kappa.flat<double>().data();
    auto dt_tensor = dt.flat<double>().data();
    auto dx_tensor = dx.flat<double>().data();
    auto m_tensor = m.flat<int64>().data();
    auto n_tensor = n.flat<int64>().data();
    auto grad_out_tensor = grad_out.flat<double>().data();
    auto out_tensor = out.flat<double>().data();
    auto grad_u_tensor = grad_u->flat<double>().data();
    auto grad_f_tensor = grad_f->flat<double>().data();
    auto grad_kappa_tensor = grad_kappa->flat<double>().data();
    auto grad_dt_tensor = grad_dt->flat<double>().data();
    auto grad_dx_tensor = grad_dx->flat<double>().data();
    auto grad_m_tensor = grad_m->flat<int64>().data();
    auto grad_n_tensor = grad_n->flat<int64>().data();   

    // implement your backward function here 

    backward(
        grad_u_tensor, grad_f_tensor, grad_kappa_tensor, 
        grad_out_tensor,
        out_tensor, u_tensor, f_tensor, kappa_tensor, *dt_tensor, *dx_tensor, *m_tensor, *n_tensor);
    
  }
};
REGISTER_KERNEL_BUILDER(Name("HeatEquationGrad").Device(DEVICE_CPU), HeatEquationGradOp);
